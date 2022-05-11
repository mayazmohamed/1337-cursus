/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:11:36 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/11 16:14:37 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include <iostream>

int main(){
    t_Serialization test;
    uintptr_t tmp1;
    t_Serialization *tmp2;

    test.a = 10;
    std::cout << test.a << std::endl;
    tmp1 = serialize(&test);
    std::cout << tmp1 << std::endl;
    tmp2 = deserialize(tmp1);
    std::cout << tmp2->a << std::endl;
    std::cout << deserialize(serialize(tmp2))->a << std::endl;
}