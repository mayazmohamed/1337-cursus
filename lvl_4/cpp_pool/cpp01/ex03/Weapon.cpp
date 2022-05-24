/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:12:04 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/13 12:11:03 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string typ)
{
	this->type = typ;
};

Weapon::Weapon()
{
};

Weapon::~Weapon()
{
};

std::string Weapon:: getType()const{
	return(this->type);
}
void Weapon:: setType(std::string typ){
	if (typ == ""){
		std::cout << "weapon not set" << std::endl;
		return;
	}
	this->type = typ;
}