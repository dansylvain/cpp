#include "Terminal.hpp"
#include <iostream>


/**========================================================================
 *                           INTERFACE
 * for increased portability, checks could be carried out to ensure that the
 * system is running a Unix-like system before executing the command.
 * But since this app will run at 42 only, 
 * we can be sure that the system is Unix-like...
 *========================================================================**/
int main(int argc, char **argv)
{
	Terminal term;

	std::string answer;
	if (argc == 1)
	{
		std::cout << "Enter 1 for tests\nEnter 2 for demo-app" << std::endl;
		while (answer != "1" && answer != "2")
		{
			std::cout << "Your choice: ";
			std::cin >> answer;
		}
		if (answer == "2")
			term.execSystemCmd(term.terminalCommand);
		else if (answer == "1")
			std::cout << "Usage: ./interface" << std::endl;
		

	}
	return 0;
	(void)argv;
}