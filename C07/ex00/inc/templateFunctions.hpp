#pragma once
#include <iostream>

//? namespace created in order to avoid function name conflict (min && max)
namespace myNameSpace
{
	template <typename T>
	void swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}

	template <typename T>
	T min(const T& a, const T& b)
	{
		return (a < b) ? a : b;
	}

	template <typename T>
	T max(const T& a, const T& b)
	{
		return (a > b) ? a : b;
	}

}

void	pause();
void	printB(std::string str);