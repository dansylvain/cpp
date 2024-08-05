#include "Zombie.hpp"

/**========================================================================
 *                           MAIN
 * Tyrone
 *========================================================================**/
int main(void)
{
	Zombie zombie("Bub");
	zombie.announce();

	Zombie *Zombina = Zombie::newZombie("Zombina");
	Zombina->announce();
	
	Zombie::randomChump("Tyrone");
	delete Zombina;
	return (0);
}