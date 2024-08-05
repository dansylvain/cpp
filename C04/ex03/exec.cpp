#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Terminal.hpp"	
#include <sstream>
#include <string>
#include <cstdlib> 
#include "unistd.h"

void	print(std::string str);
void	printB(const std::string& str);
void printFB(const std::string& str);

void	printF(std::string str);
void	test_three();

bool isDigitsOnly(const std::string& str);
Character *getCharacterByName(std::string name);
AMateria *getMateriaFromCharInv(std::string index, Character *character);
AMateria *getMateriaToCreateByIndex(std::string index, MateriaSource *source);
AMateria *getMateriaFromGround(std::string index);


void	displayAppState()
{
	printFB("			INTERFACE");
	Terminal::framingFuncOutput(AMateria::getMateriaCount() * 3, "Ground:", AMateria::displayMaterias, AMateria::displayMateriaCount);
	Terminal::framingFuncOutput(12, "Source:", MateriaSource::displayMaterias, MateriaSource::displayMateriaCount);
	for (int i = 0; i < Character::getCharacterCount(); i++)
	{
		if (Character::getCharacters()[i])
		{
			unsigned int len = Character::getCharacters()[i]->getName().length();
			std::cout << "┏";
			for (int i = 0; i < 12; i++)
			{
				std::cout << "━";
			}
			std::cout << "┓\n";
			std::cout << "┃\033[1;31m"  << Character::getCharacters()[i]->getName() << "\033[0m";
			for (unsigned int i = 0; i < 12 - len; i++)
				std::cout << " ";
			std::cout << "┃\n┃";
			Character::getCharacters()[i]->displayMaterias();
			std::cout << "┃\n┃";
			Character::getCharacters()[i]->displayMateriaCount();
			std::cout << "┃\n┗";
				for (int i = 0; i < 12; i++)
			{
				std::cout << "━";
			}
			std::cout << "┛" << std::endl;
		}
	}
}
int main()
{

	// test_three();
	
	// return 0;
	std::string userInput;
	Terminal term;
	
	MateriaSource *source = new MateriaSource;
	Character::createNewCharacter("Dan");
	
	AMateria::addMateria(ICE);
	AMateria::addMateria(CURE);
	AMateria::addMateria(ICE);


	Character::getCharacters()[0]->equip(AMateria::getMaterias()[0]);
	source->learnMateria(AMateria::getMaterias()[0]);

	while (1)
	{
		term.execSystemCmd(term.clearCommand);

		displayAppState();
		term.displayString(term.contentMenu);
	
		
		std::getline(std::cin, userInput);
		std::istringstream iss(userInput);
		std::string token;
		std::string tokens[4];
		int i = 0;


		while (iss >> token)
		{
			if (i == 5)
				break;
			tokens[i++] = token;
		}

		if (i == 3 && tokens[1] == "EQUIP" && getMateriaFromGround(tokens[2]) && getCharacterByName(tokens[0]) && !getCharacterByName(tokens[0])->getInv()[3])
			getCharacterByName(tokens[0])->equip(getMateriaFromGround(tokens[2]));
		else if (i == 3 && tokens[1] == "UNEQUIP" && getMateriaFromCharInv(tokens[2], getCharacterByName(tokens[0])) && getCharacterByName(tokens[0]))
			getCharacterByName(tokens[0])->unequip(std::atoi(tokens[2].c_str()));
		else if (i == 4 && tokens[1] == "USE" && getMateriaFromCharInv(tokens[2], getCharacterByName(tokens[0])) && getCharacterByName(tokens[0]) && getCharacterByName(tokens[3]) && tokens[3] != tokens[0])
		{
			if (getMateriaFromCharInv(tokens[2], getCharacterByName(tokens[0]))->getType() == ICE)
				std::cout << "\033[36;14H\033[1;32m* shoots an ice bolt at " + tokens[3] + " *\033[0m" << std::flush;
			else 
				std::cout << "\033[36;14H\033[1;32m* heals " + tokens[3] + "’s wounds *\033[0m" << std::flush;
			
			sleep(2);
		}
		else if (i == 2 && tokens[0] == "LEARN" && getMateriaFromGround(tokens[1]) && !getMateriaToCreateByIndex("3", source))
			source->learnMateria(getMateriaFromGround(tokens[1]));
		else if (i == 2 && tokens[0] == "CREATE" && getMateriaToCreateByIndex(tokens[1], source))
			source->createMateria(getMateriaToCreateByIndex(tokens[1], source)->getType());
		else if (i == 2 && tokens[0] == "CREATE" && !isDigitsOnly(tokens[1]))
		{
			if (tokens[1].size() > 12)
			{
				std::cout << "\033[36;11H\033[5;31m : Name too long\033[0m";
				term.displayError(term.errorMessage);
			}
			else if (Character::getCharacterCount() == 3)
			{
				std::cout << "\033[36;11H\033[5;31m : Too many characters already\033[0m";
				term.displayError(term.errorMessage);
			}
			else
			{
				Character::createNewCharacter(tokens[1]);
			}
		}
		else if (tokens[0] == "EXIT")
			break;
		else 
			term.displayError(term.errorMessage);
	}
	AMateria::cleanup();
	Character::cleanup();
	return 0;
}

void	print(std::string str)
{
	if (TEST)
		std::cout << str << std::endl;
}

void printB(const std::string& str)
{
	if (TEST)
		std::cout << "\033[1;32m" << str << "\033[0m" << std::endl;
}

void	printF(std::string str)
{
		std::cout << str << std::endl;
}

void printFB(const std::string& str)
{
	std::cout << "\033[1;32m" << str << "\033[0m" << std::endl;
}