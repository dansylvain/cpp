#include <vector>
#include <deque>

class PmergeMe
{
	private:
	public:


		typedef struct pair
		{
			int main;
			int pendant;
		};

		std::vector<pair>	_vector;
		std::deque<int>		_deque;
		std::vector<int> 	_jacobstahlSequence;
		bool				_isOdd;
		double				_straggler;

		//coplien
		PmergeMe();
		PmergeMe(const PmergeMe&);
		const PmergeMe& operator=(const PmergeMe&);
		~PmergeMe();

		// common funcs
		void	generateJacobstahlSequence(const int& intCount);
		void	createJacobstahlSequence(const int& intCount);
	
		// vector
		void	getInputVector(std::vector<int>& input);
		void	createFirstSortedPairing(std::vector<int>& _vector);
		void	sortPairsByMainChainHighestValue(std::vector<int>& _vector);
		void	insertPendantValuesThroughBinarySearch(std::vector<int>& _vector);
		void	insertStraggler(std::vector<int>& _vector);
		void	displayResults(std::vector<int>& _vector) const;

		// deque
		void	getInputDeque(std::vector<int>& input);
		void	createFirstSortedPairing(std::deque<int>& _vector);
		void	sortPairsByMainChainHighestValue(std::deque<int>& _vector);
		void	insertPendantValuesThroughBinarySearch(std::deque<int>& _vector);
		void	insertStraggler(std::deque<int>& _vector);
		void	displayResults(std::deque<int>& _vector) const;
		
};