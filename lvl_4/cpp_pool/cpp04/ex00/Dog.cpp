/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:51:43 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/06 12:16:54 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Defult Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Defult Dog destructor called" << std::endl;
}

Dog:: Dog(Dog &F){
	std::cout << "Copy Dog constructor called" << std::endl;
	*this = F;
}

Dog & Dog:: operator=(const Dog &F){
	std::cout  << "Copy assignment Dog constructor called" <<  std::endl;
	if (this != &F){
		this->type = F.type;
	}
	return *this;
}

void Dog:: makeSound()const{
	std::cout << "Woof Woof" << std::endl;
}