/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:14:50 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/11 15:37:46 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cast.hpp"
#include <iostream>

int main(int ac, char *av[]){
    int i = 1;
    try
    {
        Cast b;
        while (i < ac)
            b.printResult(av[i++]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}