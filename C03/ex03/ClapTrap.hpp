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
		std::string			Name;
		int					HitPoints;
		int					EnergyPoints;
		int					AttackDamage;

	public:
		// Constructors and destructor
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap &other);
		virtual ~ClapTrap();

		// assignment operator
		ClapTrap &operator=(const ClapTrap &src);
		
		// getters and setters
		virtual std::string		getName(void)			const;
		virtual int				getHitPoints(void)		const;
		virtual int				getEnergyPoints(void)	const;
		virtual int				getAttackDamage(void)	const;

		// other methods
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		// static utility methods
		static void 		addClapTrap(ClapTrap* clapTrap);
		static ClapTrap* 	findByName(const std::string& name);
		static const int	MAX_CLAPTRAPS = 20;
		static ClapTrap*	allClapTraps[MAX_CLAPTRAPS];
		static int 			count;

};

#endif