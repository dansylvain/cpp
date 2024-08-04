#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Terminal.hpp"	
#include <sstream>
#include <string>

void	print(std::string str);
void	printB(const std::string& str);
void printFB(const std::string& str);

void	printF(std::string str);
void	test_one();
void	test_two();
void	test_three();
void	test_four();

bool TEST;



bool isDigitsOnly(const std::string& str) {
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
		if (!std::isdigit(static_cast<unsigned char>(*it))) {
			return false;
		}
	}
	return true;
}

Character *getCharacterByName(std::string name)
{
	for (int i = 0; i < Character::characterCount; i++)
	{
		if (Character::characters[i]->getName() == name)
			return (Character::characters[i]);
	}
	return (NULL);
}

AMateria *getMateriaFromCharInv(std::string index, Character *character)
{
	if (!isDigitsOnly(index) || index.empty())
		return (NULL);
	int idx = std::atoi(index.c_str());
	if (idx < 0 && idx > 3)
		return (NULL);
	return (character->inv[idx]);
}

AMateria *getMateriaToCreateByIndex(std::string index, MateriaSource source)
{
	if (!isDigitsOnly(index) || index.empty())
		return (NULL);
	int idx = std::atoi(index.c_str());
	if (idx < 0 && idx > 4)
		return (NULL);
	return source.inv[idx];
}

AMateria *getMateriaToLearnByIndex(std::string index)
{
	if (!isDigitsOnly(index) || index.empty())
		return (NULL);
	int idx = std::atoi(index.c_str());
	if (idx < 0 && idx > 4)
		return (NULL);
	return AMateria::materias[idx];
}

AMateria *getMateriaFromGround(std::string index)
{
	if (!isDigitsOnly(index) || index.empty())
		return (NULL);
	int idx = std::atoi(index.c_str());
	if (idx < 0 && idx > 99)
		return (NULL);
	return AMateria::materias[idx];
}


int main()
{
	std::string userInput;
	Terminal term;
	Character::createNewCharacter("Dan");
	MateriaSource source;
	source.createMateria(ICE);
	Character::characters[0]->equip(AMateria::materias[0]);
	source.learnMateria(AMateria::materias[0]);
	std::cout << source.inv[0]->getType() << std::endl;

	while (1)
	{
		// term.execSystemCmd(term.clearCommand);
		term.displayString(term.contentMenu);
		std::getline(std::cin, userInput);
		std::istringstream iss(userInput);
		std::string token;
		std::string tokens[3];
		int i = 0;

		while (iss >> token)
		{
			if (i == 4)
				break;
			tokens[i++] = token;
		}

		if (i == 3 && tokens[1] == "EQUIP" && getMateriaFromGround(tokens[2]) && getCharacterByName(tokens[0]))
			printF("EQUIP MOI çA");
		else if (i == 3 && tokens[1] == "UNEQUIP" && getMateriaFromCharInv(tokens[2], getCharacterByName(tokens[0])) && getCharacterByName(tokens[0]))
			printF("UNEQUIP MOI çA");
		else if (i == 3 && tokens[1] == "USE" && getMateriaFromCharInv(tokens[2], getCharacterByName(tokens[0])) && getCharacterByName(tokens[0]))
			printF("USE MOI çA");
		else if (i == 2 && tokens[0] == "LEARN" && getMateriaFromGround(tokens[1]))
			printF("Learn noi ca");
		else if (i == 2 && tokens[0] == "CREATE" && getMateriaToCreateByIndex(tokens[1], source))
			printF("CREATE moi ca");
		else if (i == 2 && tokens[0] == "CREATE" && !isDigitsOnly(tokens[1]))
			std::cout << "create ce char: " << tokens[1] << std::endl;
		
		else 
			term.displayError(term.errorMessage);

		
	}
	return 0;

	TEST = false;
	test_four();
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