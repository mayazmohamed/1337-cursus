/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:03:10 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/05 16:11:44 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
	std::cout << "DiamondTrap  constructor called" << std::endl;
	this->name = "";
	this->setname("ClapTrap");
	this->setAD(FragTrap::getAD());
	this->setEP(ScavTrap::getEP());
	this->setHP(FragTrap::getHP());
}

DiamondTrap::~DiamondTrap()
{
	std::cout << " DiamondTrap Destructor called" << std::endl;
}

DiamondTrap:: DiamondTrap(const DiamondTrap &F){
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = F;
}

DiamondTrap::DiamondTrap(std::string name){
	this->name = name;
	this->setname("ClapTrap" + name);
	this->setAD(FragTrap::getAD());
	this->setEP(ScavTrap::getEP());
	this->setHP(FragTrap::getHP());
}


DiamondTrap & DiamondTrap:: operator = (const DiamondTrap &F){
	std::cout << "Copy assignment constructor called" << std::endl;
	if (this != &F)
	{
		this->name = F.name;
		this->setname(F.name);
		this->setAD(F.getAD());
		this->setEP(F.getEP());
		this->setHP(F.getHP());
	}
	return *this;
}

void DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}

void DiamondTrap:: whoAmI(){
	if (this->getEP() > 0 && this->getHP() > 0){
		std::cout << "DiamondTrap name id: " << this->name << "and ClapTrap name is: " << this->getname() << std::endl;
		this->setEP(this->getEP() -  1);
	}
	else
		std::cout << "you are dead or your energy is 0 " << std::endl;
}