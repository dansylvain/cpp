#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP


#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	protected:
		std::string			_name;
		int					_hitPoints;
		int					_energyPoints;
		int					_attackDamage;
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

		// utils methods
		void	DisplayName(std::string str) const;
		void	initialize(std::string str);

		// getters and setters
		virtual const std::string		&getName(void)			const;
		virtual const int				&getHitPoints(void)		const;
		virtual const int				&getEnergyPoints(void)	const;
		virtual const int				&getAttackDamage(void)	const;
		virtual	void							setHitPoints(int num);

		// using							ClapTrap::setHitPoints;
};

#endif