#include "Ice.hpp"

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
Ice::Ice() : AMateria(), id(new int(AMateria::materiaCount)), loc()
{
	*type = ICE;
	print("Ice created (default constructor)");
}

Ice::Ice(std::string const & type) : AMateria(), id(new int(AMateria::materiaCount))
{
	*Ice::type = type;
	print("Ice created (parameter constructor)");
}

Ice::Ice(const Ice& other) : AMateria(other), id(new int(AMateria::materiaCount))
{
	print("Ice created (copy constructor)");
}

Ice::~Ice()
{
	delete id;
	print("ice destroyed");
}

/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
		print("Ice copied");
		AMateria::operator=(other);
	}
	return (*this);
}

/**========================================================================
 *                                ACTION METHODS
 *========================================================================**/
AMateria* Ice::clone() const
{
	AMateria* ptr = new Ice(*this);
	print("Ice cloned");
	AMateria::addMateria(ptr);
	return (ptr);
}

void Ice::use(ICharacter& target)
{
	print("* shoots an ice bolt at " + target.getName() + " *");
}