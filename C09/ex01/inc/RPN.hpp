#include <iostream>
#include <string>
#include <list>
#include <stack>

class RPN
{
	private:
		std::stack<std::string, std::list<std::string> > _stack;
		RPN(const RPN&);
		const RPN& operator=(const RPN&);
		void	createStack(const std::string& input);
		void displayStack();
		bool checkInput(const std::string& input) const;
		double stringToInt(const std::string& str) const;
		std::string intToString(double number) const;
		typedef double (*OperationFunc)(double, double);
		void applyOperation(OperationFunc op);
		static double add(double a, double b);
		static double subtract(double a, double b);
		static double multiply(double a, double b);
		static double divide(double a, double b);
	public:
		RPN();
		~RPN();
		void	calculate(const std::string& input);
};