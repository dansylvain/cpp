#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	private:
		std::string			_name;
		int					_hitPoints;
		int					_energyPoints;
		int					_attackDamage;

		static void addClapTrap(ClapTrap* clapTrap);
		static ClapTrap* findByName(const std::string& name);
		ClapTrap();
	public:
		static const int	MAX_CLAPTRAPS = 10;
		static ClapTrap*	allClapTraps[MAX_CLAPTRAPS];
		static int 			count;
		// Constructors and destructor
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();

		// assignment operator
		ClapTrap&		operator=(const ClapTrap &src);
		
		// getters and setters
		std::string		getName(void)			const;
		int				getHitPoints(void)		const;
		int				getEnergyPoints(void)	const;
		int				getAttackDamage(void)	const;

		// other methods
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};

#endif