/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 01:17:03 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/03 11:33:28 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->fixed = 0;
}

Fixed::Fixed(const Fixed &F){
	std::cout << "Copy constructor called" << std::endl;
	*this = F;
}

Fixed & Fixed::operator = (const Fixed &F){
	if (this != &F)
	{
		std::cout << "Copy assignment constructor called" << std::endl;
		this->fixed = F.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed;
}

void Fixed::setRawBits(int const raw){
	this->fixed = raw;
}