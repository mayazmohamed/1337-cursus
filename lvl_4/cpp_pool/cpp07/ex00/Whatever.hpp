/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:13:27 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/11 18:29:35 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>
template <typename type>

void swap(type &a, type &b){
    type x;
    x = a;
    a = b;
    b = x;
}
template <typename type>
type min(type a, type b){
    if (a < b)
        return a;
    return b;
}
template <typename type>
type max(type a, type b){
    if (a > b)
        return a;
    return b;
}




#endif