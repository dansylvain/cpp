/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:38:41 by dsylvain          #+#    #+#             */
/*   Updated: 2024/08/17 10:38:41 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character	*Character::characters[100] = {NULL};
int			Character::characterCount = 0;

/**========================================================================
 *                           CONSTRUCTORS & DESTRUCTOR
 *========================================================================**/
Character::Character() : ICharacter()
{
	print("Character created (default constructor)");
	initInv();
}

Character::Character(std::string const & name) : ICharacter(), name(new std::string(name))
{
	print("Character created (parameter constructor)");
	initInv();
}

Character::Character(const Character& other) : ICharacter(), name(new std::string(*other.name))
{
	print("Character created (copy constructor)");
	initInv();
}

Character::~Character()
{
	delete name;
	print("Character destroyed");
}

/**========================================================================
 *                           ASSIGNMENT OPERATOR
 *========================================================================**/
Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		print("Character copied");
		ICharacter::operator=(other);
		*name = *other.name;
		for (int i = 0; i < 4; i++)
		{
			if (inv[i])
				inv[i] = NULL;
			if (other.inv[i])
				inv[i] = other.inv[i];
		}
	}
	return (*this);
}

/**========================================================================
 *                           GETTERS AND SETTERS
 *========================================================================**/
std::string const & Character::getName() const
{
	return (*name);
}

Character	**Character::getCharacters()
{
	return (characters);
}

int			Character::getCharacterCount()
{
	return (characterCount);
}

AMateria		**Character::getInv()
{
	return (inv);
}

/**========================================================================
 *                                ACTION METHODS
 *========================================================================**/
void Character::equip(AMateria* m)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (inv[i] == NULL && m->getLoc() != getName())
		{
			inv[i] = m;
			m->setLoc(getName());
			break;
		}
	}
	if (i == 4 && m->getLoc() != getName())
		print("Inventory full");
	else
		print(("Already equipped"));
}

void Character::equip(int idx)
{
	AMateria *m = AMateria::getMaterias()[idx];
	int i;
	for (i = 0; i < 4; i++)
	{
		if (inv[i] == NULL && m && m->getLoc() == GROUND)
		{
			inv[i] = m;
			m->setLoc(getName());
			break;
		}
	}
	if (i == 4)
		print("Inventory full");
}


void Character::unequip(int idx)
{
	if (inv[idx] && idx < 4 && idx >= 0)
	{
		inv[idx]->setLoc(GROUND);
		inv[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0 && inv[idx])
		inv[idx]->use(target);
}



/**========================================================================
 *                           UTILS METHODS
 *========================================================================**/
void Character::displayMaterias()
{
	for (int i = 0; i < 4; i++)
	{	
		if (inv[i] && inv[i]->getType() == ICE)
			std::cout << "🧊 ";
		else if (inv[i] && inv[i]->getType() == CURE)
			std::cout << "💚 ";
		else
			std::cout << "⬜ ";
	}

	
}

void Character::displayMateriaCount()
{
	for (int i = 0; i < 4; i++)
	{
		if (inv[i])
			std::cout << i << "  ";
		else
			std::cout << "   ";
	}
}

void	Character::initInv()
{
	for (int i = 0; i < 4; i++)
		inv[i] = NULL;
}

Character*	Character::createNewCharacter(const std::string &name)
{
	Character* ptr;
	ptr = new Character(name);
	if (characterCount < 100)
		characters[characterCount++] = ptr;
	print("new ICharacter created");
	return (ptr);
}

void	Character::cleanup()
{
	for (int i = 0; i < Character::characterCount; ++i)
		delete characters[i];
	for (int i = 0; i < 100; ++i)
		characters[i] = NULL;
	characterCount = 0;
}