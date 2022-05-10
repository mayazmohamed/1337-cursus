/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:05:06 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/06 12:17:03 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Defult Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Defult Cat destructor called" << std::endl;
}

Cat:: Cat(Cat &F){
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = F;
}

Cat & Cat:: operator=(const Cat &F){
	std::cout  << "Copy assignment Cat constructor called" <<  std::endl;
	if (this != &F){
		this->type = F.type;
	}
	return *this;
}

void Cat:: makeSound()const{
	std::cout << "Meow Meow" << std::endl;
}