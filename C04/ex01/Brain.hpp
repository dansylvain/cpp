#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"
#include <string>
class Brain {
	private:

	public:
		std::string 	ideas[100];
		Brain();
		Brain(const Brain *other);
		Brain& operator=(const Brain& src);
		~Brain();

		std::string& getIdea();
};

#endif