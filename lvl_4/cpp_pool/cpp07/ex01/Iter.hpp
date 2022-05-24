/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:33:50 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/23 11:13:03 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename type>
void iter(type a[], size_t b, void (*f)(type const &)){
    size_t i;
    for(i = 0; i < b; i++){
        f(a[i]);
    }
}

#endif