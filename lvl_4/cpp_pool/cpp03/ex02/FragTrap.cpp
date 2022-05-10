/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:47:30 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/05 13:42:46 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}


FragTrap::FragTrap(){
	std::cout << "Default FragTrap constructor called" << std::endl;
	this->setname("");
	this->setAD(30);
	this->setEP(100);
	this->setHP(100);
}

FragTrap::FragTrap(std::string name){
	this->setname(name);
	this->setAD(30);
	this->setEP(100);
	this->setHP(100);
}

FragTrap:: FragTrap(const FragTrap &F){
	std::cout << "Copy FragTrap constructor called" << std::endl;
	*this = F;
}


FragTrap & FragTrap::  operator=(const FragTrap &F){
	std::cout << "Copy assignment FragTrap constructor called" << std::endl;
	if (this != &F)
	{
		this->setname(F.getname());
		this->setAD(F.getAD());
		this->setEP(F.getEP());
		this->setHP(F.getHP());
	}
	return *this;

}

void FragTrap:: highFivesGuys(void){
	if (this->getEP() > 0 && this->getHP() > 0){
		std::cout << "FragTrap high fives Guys " << std::endl;
		this->setEP(this->getEP() -  1);
	}
	else
		std::cout << "you are dead or your energy is 0 " << std::endl;
}