/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:04:34 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/04 11:50:04 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
#include <iostream>

class Point
{
private:
	Fixed const x;
	Fixed const y;
public:
	Point(/* args */);
	Point(const Fixed &a, const Fixed &b);
	Point &operator = (const Point &F);
	Point(const Point &X);
	float getx();
	float gety();
	~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif