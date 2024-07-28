#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	initialize();
	print("### DiamondTrap created.");
};

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	initialize();
	print("### DiamondTrap ", Name,  " created. ###");
};

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	initialize();
	print("### DiamondTrap ", Name,  " created. ###");
};

DiamondTrap::~DiamondTrap() {
	print("### DiamondTrap ", Name,  " destroyed. ###");
};

// assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src) {
	if (this == &src)
		return *this;
	ScavTrap::operator=(src);
	return *this;
};

void	DiamondTrap::attack(const std::string& target) {
	std::cout << "### DiamondTrap ### ";
	ClapTrap::attack(target);
}

// other methods
void DiamondTrap::whoAmI() {

};


void DiamondTrap::initialize() {
		Name = ClapTrap::Name += "_clap_name";
	EnergyPoints = ScavTrap::getEnergyPoints();
	HitPoints = FragTrap::getHitPoints();
	AttackDamage = ScavTrap::getAttackDamage();
	}

void	DiamondTrap::DisplayName(std::string str) const {
	print("### DiamondTrap ", this->getName(), str);
}