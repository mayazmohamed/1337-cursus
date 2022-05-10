/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 23:32:13 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/29 23:43:49 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::~HumanB()
{
}

HumanB:: HumanB(std::string name){
	this->name = name;
}

void HumanB:: attack(){
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB:: setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}