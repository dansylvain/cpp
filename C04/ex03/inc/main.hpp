/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:38:12 by dsylvain          #+#    #+#             */
/*   Updated: 2024/08/17 10:38:12 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP

#define ICE "ice"
#define CURE "cure"
#define GROUND "ground"
#define MATERIASOURCE "materiaSource"

#include <cstdlib>

typedef enum
{
	e_ICE,
	e_CURE,
} eType;

typedef enum
{
	e_GROUND,
	e_MATERIASOURCE
} eLoc;

#define MAXMATERIA 100
#include <iostream>

void	myPause();
void	print(std::string str);
void	printB(const std::string& str);
void	print(std::string str);
void	printB(const std::string& str);
void	printF(std::string str);
void	printFB(const std::string& str);
extern bool TEST;


#endif 