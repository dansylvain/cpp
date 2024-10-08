/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:51:20 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/06 07:20:04 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int argc, char **argv)
{
	PmergeMe PmergeMe;
	std::vector<int> input;	

	if(!convertInput(argc, argv, &input))
		return (print("Error: invalid input"), 1);
	PmergeMe.vectorSort(input, PmergeMe._deque);
	PmergeMe._finalVector.clear();
	PmergeMe.vectorSort(input, PmergeMe._vector);
	PmergeMe.displayResults();


	return(0);
}