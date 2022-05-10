/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:50:46 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/29 14:04:08 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(){
	std::cout << "Creating the first Zombie, hdrabi, \"manually\"" << std::endl;
	{
		Zombie	newZombie("hdrabi");
		newZombie.announce();
	}
	std::cout << "Creating the second Zombie, izouf, using the function"
		" newZombie"<< std::endl;
	{
		Zombie	*zombie = newZombie("izouf");
		zombie->announce();
		delete zombie;
	}
	{
		std::cout << "Creating the third Zombie, momayaz, using the function"
			" randomChump"<< std::endl;
		randomChump("momayaz");
	}
}