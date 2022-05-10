/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 01:21:17 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/04 11:53:22 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	Point P(Fixed(10), Fixed(5));
	Point a;
	Point b(Fixed(10), Fixed(10));
	Point c(Fixed(20), Fixed(0));

	std::cout << (bsp(a, b, c, P) ? "P is inside abc" : " P is outside abc") << std::endl;
	return 0;
}