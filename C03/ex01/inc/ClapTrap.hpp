#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

// non member functions
void	print(std::string str);
void	print(std::string a, std::string b);
void	print(std::string a, std::string b, std::string c);
void	print(std::string a, std::string b, std::string c, std::string d);
void	print(std::string a, std::string b, int c, std::string d);
void	displayClapTraps();

class ClapTrap {
	protected:
		std::string			_name;
		int					_hitPoints;
		int					_energyPoints;
		int					_attackDamage;

	public:
		// Constructors and destructor
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();

		// assignment operator
		ClapTrap &operator=(const ClapTrap &src);
		
		// getters and setters
		std::string		getName(void)			const;
		int				getHitPoints(void)		const;
		int				getEnergyPoints(void)	const;
		int				getAttackDamage(void)	const;

		// other methods
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	DisplayName(std::string wtf);

		// static utility methods
		static void 		addClapTrap(ClapTrap* clapTrap);
		static ClapTrap* 	findByName(const std::string& name);
		static const int	MAX_CLAPTRAPS = 10;
		static ClapTrap*	allClapTraps[MAX_CLAPTRAPS];
		static int 			count;

};

#endif