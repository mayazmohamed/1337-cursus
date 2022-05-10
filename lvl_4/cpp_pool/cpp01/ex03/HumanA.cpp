/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 22:35:18 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/29 23:24:18 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::~HumanA()
{
}

HumanA:: HumanA(std::string name, Weapon &club): weapon(club){
	this->name = name;
}

void HumanA:: attack(){
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}