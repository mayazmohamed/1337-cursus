/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:04:29 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/04 11:52:05 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include "Point.hpp"

Point::Point(/* args */)
{
	(Fixed)x = 0;
	(Fixed)y = 0;
}

Point::Point(const Fixed &a, const Fixed &b)
{
	const_cast<Fixed&>(x) = a;
	const_cast<Fixed&>(y) = b;
}

Point & Point::operator = (const Point &F){
	if (this != &F)
    {
        const_cast<Fixed&>(this->x) = F.x;
        const_cast<Fixed&>(this->y) = F.y;
    }
    return *this;
};

Point:: Point(const Point &X){
	*this = X;
};

float Point:: getx(){
	return x.toFloat();
}

float Point:: gety(){
	return y.toFloat();
}

Point::~Point()
{
}