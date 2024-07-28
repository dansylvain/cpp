#include "ClapTrap.hpp"

/**========================================================================
 *                           STATIC VARS INITIALISATION
 *========================================================================**/
ClapTrap* 	ClapTrap::allClapTraps[ClapTrap::MAX_CLAPTRAPS] = { NULL };
int 		ClapTrap::count = 0;

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
ClapTrap::ClapTrap() : HitPoints(0), EnergyPoints(0), AttackDamage(0) {
	addClapTrap(this);
	print("ClapTrap created.");
}

ClapTrap::ClapTrap(const std::string& name) : Name(name), 
										HitPoints(10), 
										EnergyPoints(10), 
										AttackDamage(0) {
	addClapTrap(this);
	print("ClapTrap ", name, " created.");
}

ClapTrap::ClapTrap(const ClapTrap &other) : Name(other.Name), 
											HitPoints(other.HitPoints), 
											EnergyPoints(other.EnergyPoints), 
											AttackDamage(other.AttackDamage) {
	addClapTrap(this);
	print("ClapTrap ", Name, " created.");
}

ClapTrap::~ClapTrap() {
	count--;
	print("ClapTrap ", Name, " destroyed.");
}


/**========================================================================
 *                          ASSIGNMENT OPERATOR
 *========================================================================**/
ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
	if (this != &src)
	{
		this->Name = src.getName();
		this->HitPoints = src.getHitPoints();
		this->EnergyPoints = src.getEnergyPoints();
		this->AttackDamage = src.getAttackDamage();
	}
	return (*this);
}

/**========================================================================
 *                           ACCESSORS AND SETTERS
 *========================================================================**/
std::string ClapTrap::getName(void) const {
	return (Name);
}

int	ClapTrap::getHitPoints(void) const {
	return (HitPoints);
}

int	ClapTrap::getEnergyPoints(void) const {
	return (EnergyPoints);
}

int	ClapTrap::getAttackDamage(void) const {
	return (AttackDamage);
}

/**========================================================================
 *                           ACTION METHODS
 *========================================================================**/
void ClapTrap::attack(const std::string& target) {
	if (this->HitPoints == 0)
	{
		print(this->Name, " is dead and can't attack.");
		return ;
	}
	ClapTrap *tmp = findByName(target);
	if (tmp != NULL && tmp->getHitPoints() == 0)
	{
		print(this->Name, " attacks ", target, ", but it is already dead.");
		return ;
	}
	if (this->getEnergyPoints() == 0)
	{
		print(this->getName(), " has no energy left and can't attack.");
		return ;
	}	
	if (tmp != NULL)
	{
		print(this->getName(), " attacks ", target, 
		" and looses 1 EnergyPoint.");
		(*tmp).takeDamage(this->AttackDamage);
	}
	else
		print(target, " does not exist...");
	EnergyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->HitPoints == 0)
	{
		print(this->Name, " is already dead.");
		return ;
	}
	this->HitPoints -= amount;
	if (this->HitPoints <= 0)
	{
		print(this->getName(), " looses ", 
		amount + this->getHitPoints(), " HitPoints, and dies.");
		HitPoints = 0;
		return ;
	}
	print(this->getName(), " takes damage and looses ",
	 amount, " HitPoints.");
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->HitPoints == 0)
	{
		print(this->Name, " is dead and can't do anything.");
		return ;
	}
	if ((*this).getEnergyPoints() > 0)
	{
		print(this->getName(), " repaires itself, recovers ",
		 amount, " HitPoints, and looses 1 EnergyPoint.");
		this->HitPoints += amount;
		this->EnergyPoints--;
	}
	else
		print(this->getName(), " has no energy left and can't be repaired.");
}

/**========================================================================
 *                           CLAPTRAP MANAGEMENT METHODS
 *========================================================================**/
	void ClapTrap::addClapTrap(ClapTrap* clapTrap) {
		if (count < MAX_CLAPTRAPS) {
			allClapTraps[count++] = clapTrap;
		} else {
			print("Error: Maximum number of ClapTraps reached!");
		}
	}

ClapTrap* ClapTrap::findByName(const std::string& name) {
	for (int i = 0; i < count; ++i) {
		if (allClapTraps[i]->getName() == name) {
			return allClapTraps[i];
		}
	}
	return NULL;
}

/**========================================================================
 *                           UTILS METHODS
 *========================================================================**/


