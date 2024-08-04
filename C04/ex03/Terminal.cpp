#include "Terminal.hpp"
#include "unistd.h"

Terminal::Terminal() :
	terminalCommand("gnome-terminal --geometry=150x24 -- bash -c \"./exec; exec bash\""),
	clearCommand("clear"),
	contentMenu("\033[26;2H\033[1;32m Commands Available: \033[0m\n\n\
\033[1;31m - <NAME> EQUIP <IDX-GROUND>\033[0m 	\033[1;32m=>\033[0m	Character equips Materia\n\
\033[1;31m - <NAME> UNEQUIP <IDX-CHAR>\033[0m	\033[1;32m=>\033[0m	Character unequips Materia\n\
\033[1;31m - <NAME> USE <IDX-CHAR>\033[0m	\033[1;32m=>\033[0m	Character uses Materia\n\
\033[1;31m - LEARN <IDX-SRC>\033[0m	 	\033[1;32m=>\033[0m	Source learns Materia\n\
\033[1;31m - CREATE <IDX-SRC>\033[0m	 	\033[1;32m=>\033[0m	Source creates Materia\n\
\033[1;31m - CREATE \"NAME\"\033[0m	 	\033[1;32m=>\033[0m	Creates Character\n\n\
\033[1;32m Your choice: \033[0m"),
	headerAdd("\033[1;32m Add a New Contact\n\033[0m\n"),
	contentSearch("\033[1;32m Search Contact Form\n\033[0m\n"),
	headerDisplay("\033[1;32m Contact Details\033[0m\n"),
	promptDisplay("New search? (Y/N)"),
	errorMessage("\033[36;2H\033[5;31m Not Valid\033[0m"),
	// errorMessage("\033[36;2H\033[5;31m Not Valid"),
	contactAddedMessage("\n\033[1;32m Contact added successfully!\033[0m"),
	searchTabHeader("\033[1;31m	|     index|first name| last name|  nickname| \033[0m\n"),
	searchPrompt("\033[13;2H\033[1;32mEnter an index:                                   \
	\033[13;18H\033[0m"),
	searchEndPrompt("\033[1;32m\nPress Enter to continue...\033[0m")
	{}


void	Terminal::execSystemCmd(std::string str) const
		{std::system(str.c_str());}

void	Terminal::displayString(std::string str) const
		{std::cout << str << std::flush;};

void	Terminal::displayError(std::string str) const
		{std::cout << str << std::flush;sleep(1);};

void	Terminal::getUserinput(std::string& userInput)
		{std::getline(std::cin, userInput);};