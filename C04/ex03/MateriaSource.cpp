#include "MateriaSource.hpp"
#include <iomanip>

AMateria*		MateriaSource::inv[4] = {NULL};

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
MateriaSource::MateriaSource()
{
	print("MateriaSource Created (default constructor)");
	initInv();
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	(void)other;
	initInv();
}

MateriaSource::~MateriaSource()
{
	print("MateriaSource destroyed");
	initInv();
}


/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		print("MateriaSource copied");
	}
	return (*this);
}

/**========================================================================
 *                           ACTION METHODS
 *========================================================================**/
void MateriaSource::learnMateria(AMateria *m)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (inv[i] == NULL)
		{
			print(m->getType() + " added to inv");
			m->setLoc(MATERIASOURCE);
			inv[i] = m;
			break;
		}
	}
	if (i == 4)
		print("MateriaSource full");
	(void)m;
}
AMateria *MateriaSource::createMateria(std::string const & type)
{
	AMateria *ptr;
	if (type == CURE)
		ptr = AMateria::addMateria(new Cure(type));
	else if (type == ICE)
	{
		ptr = AMateria::addMateria(new Ice(type));
	}
	return (ptr);
}

/**========================================================================
 *                           UTILS
 *========================================================================**/

void	MateriaSource::initInv()
{
	for (int i = 0; i < 4; i++)
		inv[i] = NULL;
}

void	MateriaSource::displayMaterias()
{
	for (int i = 0; i < 4; i++)
	{
		if (inv[i] && MateriaSource::inv[i]->getType() == ICE)
			std::cout << "🧊 ";
		else if (inv[i] && MateriaSource::inv[i]->getType() == CURE)
			std::cout << "💚 ";
		else
			std::cout << "⬜ ";
	}

}

void	MateriaSource::displayMateriaCount()
{
	for (int i = 0; i < 4; i++)
	{
		if (MateriaSource::inv[i])
			std::cout << std::setw(2) << std::setfill(' ') << i << " ";
		else
			std::cout << "   " ;

	}
}
