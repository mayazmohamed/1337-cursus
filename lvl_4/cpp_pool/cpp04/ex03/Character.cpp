/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:24:25 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/07 17:24:30 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(/* args */)
{
	std::cout << "Defult Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inv[i] = nullptr;

}

Character ::Character(std::string const &name){
	for (int i = 0; i < 4; i++)
		this->inv[i] = nullptr;
	this->name = name;
}

Character::~Character()
{
	std::cout << "Defult Character destructor called" << std::endl;
}

Character:: Character(Character &F){
	std::cout << "Copy Character constructor called" << std::endl;
	*this = F;
}

Character & Character:: operator=(const Character &F){
	std::cout  << "Copy assignment Character constructor called" <<  std::endl;
	if (this != &F)
		*this = F;
	return *this;
}

std::string const & Character::getName()const{
	return this->name;
}

void Character::equip(AMateria* m){
	for (int i = 0; i < 4; i++)
	{
		if (this->inv[i] == nullptr){
			inv[i] = m;
			return;
		}
	}

	std::cout << "you can't set more then 4 materia call unequip to destroy a materia " << std::endl;
}

void Character:: use(int idx, ICharacter& target){
	inv[idx]->use(target);
}

void Character:: unequip(int idx){
	if (idx >= 0 && idx < 4){
		this->inv[idx] = nullptr;
	}
	else
	std::cout << "wrong index try again " << std::endl;
}