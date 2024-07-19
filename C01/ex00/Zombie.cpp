#include "Zombie.hpp"



Zombie::Zombie() : name("Unnamed"), mssg("BraiiiiiiinnnzzzZ...") {};

Zombie::Zombie(const std::string& name) : name(name), mssg("BraiiiiiiinnnzzzZ...") {};

void Zombie::announce(void)
{
	std::cout << this->name << ": " << this->mssg << std::endl;
}

Zombie* newZombie( std::string name )
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
}

void	randomChump( std::string name )
{
	Zombie tyrone_zombie(name);

	tyrone_zombie.announce();

}
/**========================================================================
 *                           MAIN
 * Tyrone
 *========================================================================**/
int main(void)
{
	Zombie zombie("Bub");

	Zombie *bar_zombie = newZombie("Zombina");
	zombie.announce();
	bar_zombie->announce();
	randomChump("Tyrone");
	return (0);
}