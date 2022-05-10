/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:14:28 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/06 12:16:43 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
	std::cout << "Defult Animal constructor called" << std::endl;
}

Animal::~Animal(){
	std::cout << "Defult Animal destructor called" << std::endl;
}

Animal:: Animal(std::string type){
	this->type = type;
}

Animal:: Animal(Animal &F){
	std::cout << "Copy Animal constructor called" << std::endl;
	*this = F;
}

Animal & Animal:: operator=(const Animal &F){
	std::cout  << "Copy assignment Animal constructor called" <<  std::endl;
	if (this != &F){
		this->type = F.type;
	}
	return *this;
}

void Animal:: makeSound()const {
	std::cout << "Animal sound" << std::endl;
}

std::string Animal:: getType()const{
	return this->type;
}

void  Animal:: setType(std::string type){
	this->type = type;
}