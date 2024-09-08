/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:49:51 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/08 12:44:39 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename InputContainer, typename Container>
void	PmergeMe::vectorSort(InputContainer& input, Container& _vector)
{
	clock_t timer = startTimer();
	getInputVector(input, _vector);
	generateJacobstahlSequence();
	createFirstSortedPairing(_vector);
	sortPairsByMainChainHighestValue(_vector);
	createFinalVector(_vector);
	insertPendantValuesThroughBinarySearch(_vector);
	if (_isOdd)
		insertValueThroughBinarySearch(_vector, _straggler);
	stopTimer(_vector, timer);
}

template <typename Container>
void PmergeMe::reserve_space(Container&, typename Container::size_type)
{
	// Nothing. Void. NADA-ZERO.
}

template <>
inline void PmergeMe::reserve_space(std::vector<int>& container, std::vector<int>::size_type size)
{
    container.reserve(size);
}

template <typename InputContainer, typename Container>
void PmergeMe::getInputVector(InputContainer& input, Container& _vector)
{
	_pairCount = 0;
	_comparisonCount = 0;
	_initialVector = input;
	_currentFinalVectorSize = 0;
	_intCount = input.size();
	_vector.clear();
	reserve_space(_vector, _intCount); //? specific to vector
	_isOdd = false;

	for (unsigned long i = 0; i < input.size(); i++)
	{
		Pair pair;
		pair.main = input[i];

		if (i + 1 < input.size())
		{
			pair.pendant = input[i + 1];
			_vector.push_back(pair);
			_pairCount++;
			i++;
		}
		else
		{
			_isOdd = true;
			_straggler = input[i];
		}
	}
}

template<typename Container>
void	PmergeMe::createFirstSortedPairing(Container& _vector)
{
	int tmp = 0;

	for (unsigned long i = 0; i < _vector.size(); i++)
	{
		if (_vector[i].main > _vector[i].pendant)
		{
			tmp = _vector[i].main;
			_vector[i].main = _vector[i].pendant;
			_vector[i].pendant = tmp;
			_comparisonCount++;
		}
	}
}

template<typename Container>
void	PmergeMe::sortPairsByMainChainHighestValue(Container& _vector)
{
	int len = _vector.size();
	if (len <= 1) return;

	int middle = len / 2;
	Container leftVector(_vector.begin(), _vector.begin() + middle);
	Container rightVector(_vector.begin() + middle, _vector.end());

	sortPairsByMainChainHighestValue(leftVector);
	sortPairsByMainChainHighestValue(rightVector);
	merge(leftVector, rightVector, _vector);
}

template<typename Container>
void	PmergeMe::merge(Container& leftVector, Container& rightVector,
		Container& _vector)
{
	int leftSize = leftVector.size();
	int rightSize = rightVector.size();
	int i = 0, l = 0, r = 0;

	while(l < leftSize && r < rightSize)
	{
		if(leftVector[l].main < rightVector[r].main)
			_vector[i++] = leftVector[l++];
		else
			_vector[i++] = rightVector[r++];
		_comparisonCount++;
	}
	while (l < leftSize)
		_vector[i++] = leftVector[l++];
	while (r < rightSize)
		_vector[i++] = rightVector[r++];
}

template<typename Container>
void	PmergeMe::insertPendantValuesThroughBinarySearch(Container& _vector)
{
	long unsigned int i = 0;
	if (_pairCount < 1)
		return;
	for (; i < _jacobstahlSequence.size(); i++)
	{
		unsigned long int index = _jacobstahlSequence[i] - 1;
		if (index >= _vector.size())
			break;
		int val = _vector[index].pendant;
		insertValueThroughBinarySearch(_vector, val);
	}
	_pairCount -= i;
	for (;i > 0; i--)
	{
		unsigned long int index = _jacobstahlSequence[i - 1];
		_vector.erase(_vector.begin() + index - 1);
	}
	generateJacobstahlSequence();
	insertPendantValuesThroughBinarySearch(_vector);
}

template<typename Container>
void PmergeMe::insertValueThroughBinarySearch(Container&, int val)
{
	int low = 0;
	int high = _currentFinalVectorSize - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (_finalVector[mid] < val)
			low = mid + 1;
		else
			high = mid - 1;
		_comparisonCount++;
	}
	_finalVector.insert(_finalVector.begin() + low, val);
	_currentFinalVectorSize++;
}


template<typename Container>
void	PmergeMe::createFinalVector(Container& _vector)
{
	reserve_space(_finalVector, _intCount);
	for (int i = 0; i < _pairCount; i++)
	{
		_finalVector.push_back(_vector[i].main);
		_currentFinalVectorSize++;
	}
}

template<typename Container>
void PmergeMe::stopTimer(Container&, clock_t start)
{
	(void)start;
	
}

template<>
inline void	PmergeMe::stopTimer(std::vector<Pair>&, clock_t start)
{
	clock_t end = clock();
	_timeSpentVector = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

template<>
inline void	PmergeMe::stopTimer(std::deque<Pair>&, clock_t start)
{
	clock_t end = clock();
	_timeSpentDeque = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}