/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:17:36 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/05 12:42:51 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "Default ClapTrap constructor called" << std::endl;
	this->name = "";
	this->AD = 0;
	this->EP = 10;
	this->HP = 10;
}

ClapTrap::ClapTrap(std::string &name){
	// std::cout << "" << std::endl;
	this->name = name;
	this->AD = 0;
	this->EP = 10;
	this->HP = 10;
}

ClapTrap:: ~ClapTrap(){
	std::cout << "Destructor called" << std::endl;
}

ClapTrap:: ClapTrap(const ClapTrap &F){
	std::cout << "Copy constructor called" << std::endl;
	*this = F;
}

ClapTrap & ClapTrap:: operator = (const ClapTrap &F){
	std::cout << "Copy assignment constructor called" << std::endl;
	if (this != &F)
	{
		this->HP = F.HP;
		this->AD = F.AD;
		this->EP = F.EP;
		this->name = F.name;
	}
	return *this;
}

int ClapTrap:: getAD() const{
	return this->AD;
}

int ClapTrap:: getHP() const{
	return this->HP;
}

int ClapTrap:: getEP() const{
	return this->EP;
}

std::string ClapTrap:: getname() const{
	return this->name;
}

void ClapTrap:: setAD(int AD){
	this->AD = AD;
}

void ClapTrap:: setHP(int HP){
	this->HP = HP;
}

void ClapTrap:: setEP(int EP){
	this->EP = EP;
}

void ClapTrap:: setname(std::string name){
	this->name = name;
}

void ClapTrap:: attack(const std::string& target){
	if (this->EP > 0 && this->HP > 0){
		std::cout << "ClapTrap: "<< this->name <<" attacks "<< target << " causing " << this->AD << " points of damage!" << std::endl;
		this->EP -= 1;
	}
	else
		std::cout << "you are dead or your energy is 0 " << std::endl;
}

void ClapTrap:: takeDamage(unsigned int amount){
	if (this->EP > 0 && this->HP > 0){
	std::cout << "ClapTrap: "<< this->name <<" is taking a damage of : "<< amount << std::endl;
	this->HP -= amount;
	}
	if (this->HP <= 0)
		std::cout << "ClapTrap: "<< this->name <<" is dead !" << std::endl;
}

void ClapTrap:: beRepaired(unsigned int amount){
	if (this->EP > 0 && this->HP > 0){
		std::cout << "ClapTrap: "<< this->name <<" is repaired !" << amount << std::endl;
		this->HP += amount;
		this->EP -= 1;
	}
	else
		std::cout << "you are dead or your energy is 0 " << std::endl;
}
