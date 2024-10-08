#include "MutantStack.hpp"

/**========================================================================
 *                           COPLIEN
 *========================================================================**/

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other) : std::stack<T, Container>(other)
{
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other)
{
    if (this != &other)
	{
        std::stack<T, Container>::operator=(other);
    }
    return *this;
}

/**========================================================================
 *                           UTILS
 *========================================================================**/
template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::begin()
{
    return this->c.begin();
}

template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::end()
{
    return this->c.end();
}

template <typename T, typename Container>
typename Container::const_iterator MutantStack<T, Container>::begin() const
{
    return this->c.begin();
}

template <typename T, typename Container>
typename Container::const_iterator MutantStack<T, Container>::end() const
{
    return this->c.end();
}
