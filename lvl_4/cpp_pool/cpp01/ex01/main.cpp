/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:35:24 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/29 14:47:51 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(){
	std::cout << "creat array N zombies" << std::endl;
	Zombie* zombies = zombieHorde(5, "hdrabi");
	delete [] zombies;

}