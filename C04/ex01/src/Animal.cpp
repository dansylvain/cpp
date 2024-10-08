#include "main.hpp"

/**========================================================================
 *                           CONSTRUCTORS AND DESTRUCTOR
 *========================================================================**/
Animal::Animal() : type("Animal")
{
	print("Animal created");
}

Animal::Animal(const Animal &other)
{
	print("Animal created");
	type = other.getType();
}

Animal::~Animal()
{
	print("Animal destroyed");
}

/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
Animal& Animal::operator=(const Animal& src)
{
	if (this != &src)
		this->type = src.getType();
	return (*this);
}

/**========================================================================
 *                           GETTERS AND SETTERS>
 *========================================================================**/
void	Animal::makeSound() const
{
	print(getType() + " says hi");
}

const std::string	&Animal::getType() const
{
	return (type);
}
