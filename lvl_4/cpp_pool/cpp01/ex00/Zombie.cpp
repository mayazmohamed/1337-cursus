/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:25:29 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/13 11:35:40 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void Zombie:: announce(){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie:: Zombie(std::string name){
	this->name = name;
}

Zombie:: ~Zombie(){
	std::cout << this->name << " dying" << std::endl;
}

