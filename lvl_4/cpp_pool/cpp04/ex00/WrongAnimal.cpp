/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:30:30 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/17 13:30:31 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal()
{
	_type = "";
	std::cout << "\e[0;33mDefault Constructor called of WrongAnimal\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	_type = copy.getType();
	std::cout << "\e[0;33mCopy Constructor called of WrongAnimal\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	_type = type;
	std::cout << "\e[0;33mFields Constructor called of WrongAnimal\e[0m" << std::endl;
}


// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[0;31mDestructor called of WrongAnimal\e[0m" << std::endl;
}


// Operators
WrongAnimal & WrongAnimal::operator=(const WrongAnimal &assign)
{
	_type = assign.getType();
	return *this;
}


// Getters / Setters
std::string WrongAnimal::getType() const
{
	return _type;
}

void WrongAnimal::setType(std::string type){
	this->_type = type;
}

void WrongAnimal:: makeSound()const {
	std::cout << "Animal sound" << std::endl;
}