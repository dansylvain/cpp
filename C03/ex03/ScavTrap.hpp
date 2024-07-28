#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP


#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	protected:
		std::string			Name;
		int					HitPoints;
		int					EnergyPoints;
		int					AttackDamage;
	public:
		// Constructors and destructor
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();

		// assignment operator
	    ScavTrap& operator=(const ScavTrap& src);

		// action methods
		void	attack(const std::string& target);
		void	guardGate() const;

		int		getEnergyPoints(void)	const;
		
		// utils methods
		void	DisplayName(std::string str) const;
		void	initialize(std::string str);
};

#endif