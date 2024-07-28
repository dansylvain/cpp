#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP


#include "ClapTrap.hpp"

class FragTrap : virtual 	public ClapTrap {
	protected:
		std::string			Name;
		int					HitPoints;
		int					EnergyPoints;
		int					AttackDamage;
	public:
		// Constructors and destructor
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap &other);
		~FragTrap();

		// assignment operator
	    FragTrap& operator=(const FragTrap& src);

		// action methods
		void	attack(const std::string& target);
		void	highFivesGuys(void) const;

		// std::string		getName(void)			const;
		int				getHitPoints(void)		const;
		int				getAttackDamage(void)	const;

		// utils methods
		void	DisplayName(std::string str) const;
		void	initialize(void);
};

#endif