#pragma once
#include <cfloat>
#include <climits>
#include <iostream>
#include <string>
#include <iomanip>


template <typename T>
void printConversions(T value)
{
    std::cout << "char: ";
    if (value < 0 || value > 127 || !isprint(static_cast<int>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "\'" << static_cast<char>(value) << "\'" << std::endl;

    std::cout << "int: ";
    if (value < static_cast<T>(INT_MIN) || value > static_cast<T>(INT_MAX))
        std::cout << "Impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;

    std::cout << "float: ";
    if (static_cast<float>(value) < -FLT_MAX || static_cast<float>(value) > FLT_MAX)
        std::cout << "Impossible" << std::endl;
    else
	{
		std::cout << std::fixed << std::setprecision(static_cast<int>(value) == value ? 1 : 6);
        std::cout << static_cast<float>(value) << "f" << std::endl;
	}
	std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(static_cast<int>(value) == value ? 1 : 6);
    std::cout << static_cast<double>(value) << std::endl;
}

