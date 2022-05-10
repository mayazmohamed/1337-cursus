/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 01:18:17 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/04 11:32:06 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_
#define _FIXED_

#include <iostream>
#include <fstream>
#include <cmath>

class Fixed
{
    private:
        int fixed;
        static const int fA = 8;
    public:
        Fixed();
		Fixed(const int f);
		Fixed(const float f);
        Fixed(const Fixed &F);
        Fixed &operator = (const Fixed &F);
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
		bool operator== (const Fixed& c1);
		bool operator!= (const Fixed& c1);
		bool operator< (const Fixed& c1);
		bool operator> (const Fixed& c1);
		bool operator<= (const Fixed& c1);
		bool operator>= (const Fixed& c1);
		Fixed operator+ (const Fixed& c1);
		Fixed operator- (const Fixed& c1);
		Fixed operator* (const Fixed& c1);
		Fixed operator/ (const Fixed& c1);
		Fixed operator++ ();
		Fixed operator-- ();
		Fixed operator++ (int);
		Fixed operator-- (int);
		static Fixed max(Fixed &c1, Fixed &c2);
		static const Fixed max(const Fixed &c1, const Fixed &c2);
		static Fixed min(Fixed &c1, Fixed &c2);
		static const Fixed min(const Fixed &c1, const Fixed &c2);
};
std::ostream & operator<< (std::ostream &out, const Fixed &c);


#endif