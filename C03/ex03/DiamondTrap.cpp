#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {

}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), 
										FragTrap(name),
										Name(name), 
										HitPoints(FragTrap::getHitPoints()), 
										EnergyPoints(ScavTrap::getEnergyPoints()), 
										AttackDamage(FragTrap::getAttackDamage())   {
(void)name;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)  : ClapTrap(other), ScavTrap(other), FragTrap() {
	
}

DiamondTrap::~DiamondTrap() {

}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src) {
(void)src;
	if (this == &src)
		return *this;
	ClapTrap::operator=(src);
	ScavTrap::operator=(src);
	FragTrap::operator=(src);
	return *this;
return (*this);
}


/**========================================================================
 *                           ACCESSORS AND SETTERS
 *========================================================================**/
const std::string &DiamondTrap::getName(void) const {
	return (Name);
}

const int	&DiamondTrap::getHitPoints(void) const {
	return (HitPoints);
}

const int	&DiamondTrap::getEnergyPoints(void) const {
	return (EnergyPoints);
}

const int	&DiamondTrap::getAttackDamage(void) const {
	return (AttackDamage);
}