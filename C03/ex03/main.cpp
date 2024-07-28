#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void	displayClapTraps()
{
	print("");
	print("*** Display: (Name, EnergyPoints, HitPoints, AttackDamage) ***");
	for (int i = 0; i < ClapTrap::count; i++)
		std::cout << i + 1 << " - " << ClapTrap::allClapTraps[i]->getName() << ", "
		<< ClapTrap::allClapTraps[i]->getEnergyPoints() << ", "
		<< ClapTrap::allClapTraps[i]->getHitPoints() << ", "
		<< ClapTrap::allClapTraps[i]->getAttackDamage()
		<< "." << std::endl;
	print("");	
}

int main(void)
{
	print("****** Create ClapTraps ******");
	ClapTrap	ClappyClappo("ClappyClappo");
	ClapTrap::addClapTrap(&ClappyClappo);
	ScavTrap	Clapster("Clapster");
	ClapTrap::addClapTrap(&Clapster);
	ClapTrap	ZappyClap("ZappyClap");
	ClapTrap::addClapTrap(&ZappyClap);
	ScavTrap	ScavMaster("ScavMaster");
	ClapTrap::addClapTrap(&ScavMaster);
	ScavTrap	ScavTronix("ScavTronix");
	ClapTrap::addClapTrap(&ScavTronix);
	ScavTrap	GigaScav("GigaScav");
	ClapTrap::addClapTrap(&GigaScav);
	ScavTrap	ScavBuddy("ScavBuddy");
	ClapTrap::addClapTrap(&ScavBuddy);
	FragTrap	FraggyBoy("FraggyBoy");
	ClapTrap::addClapTrap(&FraggyBoy);
	DiamondTrap	PreciousTrap("PreciousTrap");
	ClapTrap::addClapTrap(&PreciousTrap);
	
	displayClapTraps();
	
	print("******* test: attack *********");
	Clapster.attack("NonExistingClapTrap");
	Clapster.attack("");
	Clapster.attack("ScavTronix");
	Clapster.attack("ScavTronix");
	Clapster.attack("ScavTronix");
	Clapster.attack("ScavTronix");
	Clapster.attack("ScavTronix");
	Clapster.attack("ScavTronix");
	ScavTronix.attack("Clapster");
	print("");
	ZappyClap.attack("GigaScav");
	
	print("***** test: takeDamage *******");
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	ScavMaster.takeDamage(22);
	print("");

	print("***** test: beRepaired *******");
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	ClappyClappo.beRepaired(1);
	print("");

	print("****** special Traps tests ******");
	ScavBuddy.guardGate();
	FraggyBoy.highFivesGuys();
	
	displayClapTraps();


	std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%TESTS%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
	std::cout << PreciousTrap.getAttackDamage() << std::endl;

	print("****** Detroy Claptraps ******");
	return (0);
}

void	print(std::string a) {
	std::cout << a << std::endl;
}
void	print(std::string a, std::string b) {
	std::cout << a << b << std::endl;
}
void	print(std::string a, std::string b, std::string c) {
	std::cout << a << b << c << std::endl;
}
void	print(std::string a, std::string b, std::string c, std::string d) {
	std::cout << a << b << c << d << std::endl;
}
void	print(std::string a, std::string b, int c, std::string d) {
	std::cout << a << b << c << d << std::endl;
}