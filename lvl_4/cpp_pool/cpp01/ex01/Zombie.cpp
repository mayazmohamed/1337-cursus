/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:16:01 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/29 14:43:26 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void Zombie:: announce(){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie:: Zomb(std::string name){
	this->name = name;
}

Zombie:: Zombie(){
	
}

Zombie:: ~Zombie(){
	std::cout << "Zombie dying" << std::endl;
}
