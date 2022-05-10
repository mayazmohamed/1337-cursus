/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 01:17:03 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/03 11:54:42 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->fixed = 0;
}

Fixed::Fixed(const int f){
	std::cout << "Int constructor called" << std::endl;
	fixed = (int)(roundf(f * (1 << fA)));
}

Fixed::Fixed(const float f){
	std::cout << "Float constructor called" << std::endl;
	fixed = (int)(roundf(f * (1 << fA)));
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
	return this->fixed;
}

void Fixed::setRawBits(int const raw){
	this->fixed = raw;
}

float Fixed:: toFloat( void ) const{
	return ((double)this->fixed / (double)(1 << fA));
}

int Fixed:: toInt( void ) const{
	return ((int)this->fixed / (int)(1 << fA));
}

std::ostream & operator << (std::ostream &out, const Fixed &c){
	out << c.toFloat();
	return out;
}