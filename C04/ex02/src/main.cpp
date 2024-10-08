#include "main.hpp"

/**========================================================================
 *                           MAIN
 * abstract classes cannot be instantiated
 * create a pure fonction (by adding = 0 at the end)
 * to make a class abstract
 *========================================================================**/
int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	// AAnimal test;

	print("Welcome to the Jungle");
	print("");

	printB("******** AAnimal Creation ***********");
	AAnimal* animals[10];
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();
	print("");
	pause();
	printB("********** Brain Tests *************");
	for (int i = 0; i < 10; i++)
	{
		if (i == 5) print("");
		std::string str = (animals[i])->getType() + " thinks: ";
		const Dog *dogPtr = dynamic_cast<const Dog*>(animals[i]);
		const Cat *CatPtr = dynamic_cast<const Cat*>(animals[i]);
		dogPtr ? print(str + dogPtr->getBrain()->getIdea()) : 
		print(str + CatPtr->getBrain()->getIdea());
	}
	pause();
	print("");
	printB("**** Copy constructor test *********");
	const Cat *catPtr = dynamic_cast<Cat*>(animals[8]);
	print("PussyCat thinks: " + catPtr->getBrain()->getIdeas()[7]);
	print("PussyCat thinks: " + catPtr->getBrain()->getIdeas()[15]);
	print("PussyCat thinks: " + catPtr->getBrain()->getIdeas()[42]);

	print("");
	Cat copyCat(*catPtr);
	print("");

	print("Pussy thinks:   " + catPtr->getBrain()->getIdeas()[7]);
	print("copyCat thinks: " + copyCat.getBrain()->getIdeas()[7]);
	print("Pussy thinks:   " + catPtr->getBrain()->getIdeas()[15]);
	print("copyCat thinks: " + copyCat.getBrain()->getIdeas()[15]);
	print("Pussy thinks:   " + catPtr->getBrain()->getIdeas()[42]);
	print("copyCat thinks: " + copyCat.getBrain()->getIdeas()[42]);


	pause();
	print("");
	printB("***** Assignment Tests *************");
	Dog *dogOne = dynamic_cast<Dog*>(animals[4]);
	Dog *dogTwo = dynamic_cast<Dog*>(animals[2]);
	
	print("before assignment");
	print("dogOne thinks: " + dogOne->getBrain()->getIdeas()[42]);
	print("dogTwo thinks: " + dogTwo->getBrain()->getIdeas()[42]);
	print("dogOne thinks: " + dogOne->getBrain()->getIdeas()[12]);
	print("dogTwo thinks: " + dogTwo->getBrain()->getIdeas()[12]);
	print("dogOne thinks: " + dogOne->getBrain()->getIdeas()[5]);
	print("dogTwo thinks: " + dogTwo->getBrain()->getIdeas()[5]);
	print("");

	*dogOne = *dogTwo;

	print("");
	print("after assignment");
	print("dogOne thinks: " + dogOne->getBrain()->getIdeas()[42]);
	print("dogTwo thinks: " + dogTwo->getBrain()->getIdeas()[42]);
	print("dogOne thinks: " + dogOne->getBrain()->getIdeas()[12]);
	print("dogTwo thinks: " + dogTwo->getBrain()->getIdeas()[12]);
	print("dogOne thinks: " + dogOne->getBrain()->getIdeas()[5]);
	print("dogTwo thinks: " + dogTwo->getBrain()->getIdeas()[5]);
	print("");

	pause();
	printB("******* Animals destruction ********");
	for (int i = 0; i < 10; i++)
		delete animals[i];
	return 0;
	(void)animals;
}