/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:33:53 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/23 11:16:54 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>

template <typename T>
void display(T &i){
    std::cout << i << std::endl;
}

int main( void ) {
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    float f[10] = {0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9};
    char c[10] = {'a','b','c','d','e','f','g','h','i','j'};
    
    iter(a, 10, &display);
    iter(f, 10, &display);
    iter(c, 10, &display);
    return 0;
}