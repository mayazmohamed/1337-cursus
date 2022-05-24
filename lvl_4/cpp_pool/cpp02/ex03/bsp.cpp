/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:04:19 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/13 12:46:38 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

float sign (Point p1, Point p2, Point p3)
{
    return (((p1.getx() - p3.getx()) * (p2.gety() - p3.gety())) - ((p2.getx() - p3.getx()) * (p1.gety() - p3.gety())));
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	float d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(point, a, b);
    d2 = sign(point, b, c);
    d3 = sign(point, c, a);
    // std::cout << d1 << d2 << d3 << std::endl;
    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}