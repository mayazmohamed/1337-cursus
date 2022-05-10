/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 01:18:17 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/03 11:34:18 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_
#define _FIXED_

#include <iostream>

class Fixed
{
    private:
        int fixed;
        static const int fA = 8;
    public:
        Fixed();
        Fixed(const Fixed &F);
        Fixed &operator = (const Fixed &F);
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int const raw);
};



#endif