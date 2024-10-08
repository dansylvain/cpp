/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Terminal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:41:00 by dsylvain          #+#    #+#             */
/*   Updated: 2024/08/17 10:45:09 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Terminal.hpp"

Terminal::Terminal() :
	terminalCommand("gnome-terminal --geometry=100x36 -- bash -c \"./src/exec\""),
	clearCommand("clear"),
	contentMenu("\033[26;2H\033[1;32m Commands Available: \033[0m\n\
\033[1;31m - CREATE <IDX-SRC>\033[0m		 	\033[1;32m=>\033[0m	Source creates Materia\n\
\033[1;31m - CREATE \"NAME\"\033[0m	 		\033[1;32m=>\033[0m	Creates Character\n\
\033[1;31m - LEARN <IDX-SRC>\033[0m	 		\033[1;32m=>\033[0m	Source learns Materia\n\
\033[1;31m - <NAME> EQUIP <IDX-GROUND>\033[0m 		\033[1;32m=>\033[0m	Character equips Materia\n\
\033[1;31m - <NAME> UNEQUIP <IDX-CHAR>\033[0m		\033[1;32m=>\033[0m	Character unequips Materia\n\
\033[1;31m - <NAME> USE <IDX-CHAR> <NAME>\033[0m		\033[1;32m=>\033[0m	Character uses Materia\n\
\033[1;31m - EXIT \033[0m			 	\033[1;32m=>\033[0m	Quit the app\n\n\
\033[1;32m Your choice: \033[0m"),
	errorMessage("\033[?25l\033[36;2H\033[5;31m Not Valid\033[0m")
		{}

void	Terminal::framingFuncOutput(int len, std::string title, void (*f1)(void), void (*f2)(void))
{
	if (len < 8)
		len = 8; 
	std::cout << "┏";
	for (int i = 0; i < len; i++)
		std::cout << "━";
	std::cout << "┓\n" << "┃\033[1;31m"  << title << "\033[0m";
	for (unsigned int i = 0; i < len - title.size(); i++)
		std::cout << " ";
	std::cout << "┃\n┃";
	f1();
	std::cout << "┃\n┃";
	f2();
	std::cout << "┃\n┗";
		for (int i = 0; i < len; i++)
		std::cout << "━";
	std::cout << "┛" << std::endl;
}

void	Terminal::FramingFuncOutputNoMethod(int *i)
{
	if (Character::getCharacters()[*i])
	{
		unsigned int len = Character::getCharacters()[*i]->getName().length();
		std::cout << "┏";
		for (int i = 0; i < 12; i++)
			std::cout << "━";
		std::cout << "┓\n";
		std::cout << "┃\033[1;31m"  << Character::getCharacters()[*i]->getName() << "\033[0m";
		for (unsigned int i = 0; i < 12 - len; i++)
			std::cout << " ";
		std::cout << "┃\n┃";
		Character::getCharacters()[*i]->displayMaterias();
		std::cout << "┃\n┃";
		Character::getCharacters()[*i]->displayMateriaCount();
		std::cout << "┃\n┗";
			for (int i = 0; i < 12; i++)
			std::cout << "━";
		std::cout << "┛" << std::endl;
	}
}

void Terminal::displayAppState()
{
	std::cout << "\033[1;31m			INTERFACE\033[0m" << std::endl;
	Terminal::framingFuncOutput(AMateria::getMateriaCount() * 3, "Ground:", AMateria::displayMaterias, AMateria::displayMateriaCount);
	Terminal::framingFuncOutput(12, "Source:", MateriaSource::displayMaterias, MateriaSource::displayMateriaCount);
	for (int i = 0; i < Character::getCharacterCount(); i++)
		Terminal::FramingFuncOutputNoMethod(&i);
}

void	Terminal::execSystemCmd(std::string str) const
		{std::system(str.c_str());}

void	Terminal::displayString(std::string str) const
		{std::cout << str << std::flush;};

void	Terminal::displayError(std::string str) const
		{std::cout << str << std::flush;sleep(2);std::cout << "\033[?25h";};
