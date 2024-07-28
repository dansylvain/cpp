#include "FragTrap.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
FragTrap::FragTrap() : ClapTrap() {}
 
FragTrap::FragTrap(const std::string& name) : 	ClapTrap(name),
												Name(name),
												HitPoints(150),
												EnergyPoints(100), 
												AttackDamage(130) {}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other),
											Name(other.Name),
											HitPoints(other.HitPoints), 
											EnergyPoints(other.EnergyPoints), 
											AttackDamage(other.AttackDamage) {}

FragTrap::~FragTrap() {
	DisplayName(" destroyed @@@");};

/**========================================================================
 *                          ASSIGNMENT OPERATOR
 *========================================================================**/
FragTrap& FragTrap::operator=(const FragTrap& src) {
	if (this == &src)
		return *this;
	ClapTrap::operator=(src);
	return *this;
}

/**========================================================================
 *                           ACTION METHODS
 *========================================================================**/
void	FragTrap::attack(const std::string& target) {
	std::cout << "@@@ FragTrap @@@ ";
	ClapTrap::attack(target);
}

void	FragTrap::highFivesGuys() const {
	print(this->getName(), " sends a high five, guys.");
}

void	FragTrap::DisplayName(std::string str) const {
	print("@@@ FragTrap ", this->getName(), str);
}

void FragTrap::initialize(void) {
	FragTrap::EnergyPoints = 100;
	FragTrap::HitPoints = 150;
	FragTrap::AttackDamage = 30;
	DisplayName(" created @@@");
}

int	FragTrap::getHitPoints(void) const {
	return (HitPoints);
}

int	FragTrap::getAttackDamage(void) const {
	return (AttackDamage);
}