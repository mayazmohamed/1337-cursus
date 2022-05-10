/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 01:17:03 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/03 14:01:16 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(){
	// std::cout << "Default constructor called" << std::endl;
	this->fixed = 0;
};

Fixed::Fixed(const int f){
	// std::cout << "Int constructor called" << std::endl;
	fixed = (int)(roundf(f * (1 << fA)));
};

Fixed::Fixed(const float f){
	// std::cout << "Float constructor called" << std::endl;
	fixed = (int)(roundf(f * (1 << fA)));
};

Fixed::Fixed(const Fixed &F){
	// std::cout << "Copy constructor called" << std::endl;
	*this = F;
};

Fixed & Fixed::operator = (const Fixed &F){
	if (this != &F)
	{
		// std::cout << "Copy assignment constructor called" << std::endl;
		this->fixed = F.getRawBits();
	}
	return *this;
};

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits() const {
	return this->fixed;
};

void Fixed::setRawBits(int const raw){
	this->fixed = raw;
};

float Fixed:: toFloat( void ) const{
	return ((double)this->fixed / (double)(1 << fA));
};

int Fixed:: toInt( void ) const{
	return ((int)this->fixed / (int)(1 << fA));
};

std::ostream & operator<< (std::ostream &out, const Fixed &c){
	out << c.toFloat();
	return out;
};

bool Fixed:: operator== (const Fixed& c1){
	return (fixed == c1.fixed);
};
bool Fixed:: operator!= (const Fixed& c1){
	return (fixed != c1.fixed);
};
bool Fixed:: operator< (const Fixed& c1){
	return (fixed < c1.fixed);
};
bool Fixed:: operator> (const Fixed& c1){
	return (fixed > c1.fixed);
};
bool Fixed:: operator<= (const Fixed& c1){
	return (fixed <= c1.fixed);
};
bool Fixed:: operator>= (const Fixed& c1){
	return (fixed >= c1.fixed);

};

Fixed Fixed:: operator+ (const Fixed& c1){
	Fixed res;

	res.fixed += c1.fixed;
	return (res);
};
Fixed Fixed:: operator- (const Fixed& c1){
	Fixed res;

	res.fixed -= c1.fixed;
	return (res);
};
Fixed Fixed:: operator* (const Fixed& c1){
	Fixed res (this->toFloat() * c1.toFloat());

	return (res);
};
Fixed Fixed:: operator/ (const Fixed& c1){
	Fixed res (this->toFloat() / c1.toFloat());

	return (res);
};

Fixed Fixed:: operator++ (){
	Fixed tmp;
	++fixed;
	tmp.fixed = fixed;
	return tmp;
};
Fixed Fixed:: operator-- (){
	Fixed tmp;
	--fixed;
	tmp.fixed = fixed;
	return tmp;
};
Fixed Fixed:: operator++ (int){
	Fixed tmp;

	tmp.fixed = fixed++;
	return tmp;
};
Fixed Fixed:: operator-- (int){
	Fixed tmp;

	tmp.fixed = fixed--;
	return tmp;
};

Fixed Fixed:: max(Fixed &c1, Fixed &c2){
	if (c1 > c2)
		return (c1);
	return (c2);
};
const Fixed Fixed:: max(const Fixed &c1, const Fixed &c2){
	if ((Fixed)c1 > (Fixed)c2)
		return (c1);
	return (c2);
};
Fixed Fixed:: min(Fixed &c1, Fixed &c2){
	if (c1 < c2)
		return (c1);
	return (c2);
};
const Fixed Fixed:: min(const Fixed &c1, const Fixed &c2){
	if ((Fixed)c1 < (Fixed)c2)
		return (c1);
	return (c2);
};
