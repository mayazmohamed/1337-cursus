/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:48:20 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/05 13:44:45 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(/* args */){
	std::cout << "Default ScavTrap constructor called" << std::endl;
	this->setname("");
	this->setAD(20);
	this->setEP(50);
	this->setHP(100);
}

ScavTrap::ScavTrap(std::string name){
	this->setname(name);
	this->setAD(20);
	this->setEP(50);
	this->setHP(100);
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap:: attack(const std::string& target){
	if (this->getEP() > 0 && this->getHP() > 0){
		std::cout << "ScavTrap: "<< this->getname() <<" attacks "<< target << " causing " << this->getAD() << " points of damage!" << std::endl;
		this->setEP(this->getEP() -  1);
	}
	else
		std::cout << "you are dead or your energy is 0 " << std::endl;
}

void ScavTrap:: guardGate(){
	if (this->getEP() > 0 && this->getHP() > 0){
		std::cout << "ScavTrap is now in Gate keeper mode " << std::endl;
		this->setEP(this->getEP() -  1);
	}
	else
		std::cout << "you are dead or your energy is 0 " << std::endl;

}

ScavTrap:: ScavTrap(const ScavTrap &F){
	std::cout << "Copy ScavTrap constructor called" << std::endl;
	*this = F;
}


ScavTrap & ScavTrap::  operator=(const ScavTrap &F){
	std::cout << "Copy assignment ScavTrap constructor called" << std::endl;
	if (this != &F)
	{
		this->setname(F.getname());
		this->setAD(F.getAD());
		this->setEP(F.getEP());
		this->setHP(F.getHP());
	}
	return *this;

}
