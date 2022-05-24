/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:15:36 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/17 13:29:24 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat()
{
	this->setType("WrongCat");
	std::cout << "\e[0;33mDefault Constructor called of WrongCat\e[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	this->setType(copy.getType());
	std::cout << "\e[0;33mCopy Constructor called of WrongCat\e[0m" << std::endl;
}

WrongCat::WrongCat(std::string type)
{
	this->setType(type);
	std::cout << "\e[0;33mFields Constructor called of WrongCat\e[0m" << std::endl;
}


// Destructor
WrongCat::~WrongCat()
{
	std::cout << "\e[0;31mDestructor called of WrongCat\e[0m" << std::endl;
}


// Operators
WrongCat & WrongCat::operator=(const WrongCat &assign)
{
	this->setType(assign.getType());
	return *this;
}

void WrongCat:: makeSound()const{
	std::cout << "Meow Meow" << std::endl;
}
