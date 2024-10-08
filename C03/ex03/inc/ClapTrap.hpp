#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

// non member functions
void	print(std::string str);
void	print(std::string a, std::string b);
void	print(std::string a, std::string b, std::string c);
void	print(std::string a, std::string b, std::string c, std::string d);
void	print(std::string a, std::string b, int c, std::string d);
void	print(int n);
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
		virtual const std::string		&getName(void)			const;
		virtual const int				&getHitPoints(void)		const;
		virtual const int				&getEnergyPoints(void)	const;
		virtual const int				&getAttackDamage(void)	const;
		virtual void					setHitPoints(int num);
		

		// other methods
		void	attack(const std::string& target);
		void	attack(const std::string& target, int AD);
		void	takeDamage(unsigned int amount);
		void	takeDamage(unsigned int amount, int HP);
		void	beRepaired(unsigned int amount);

		// static utility methods
		static void 		addClapTrap(ClapTrap* clapTrap);
		static void			displayClapTraps();
		static ClapTrap* 	findByName(const std::string& name);
		static const int	MAX_CLAPTRAPS = 50;
		static ClapTrap*	allClapTraps[MAX_CLAPTRAPS];
		static int 			count;

};

#endif