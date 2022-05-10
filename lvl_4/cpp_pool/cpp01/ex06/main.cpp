/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:02:08 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/30 21:51:07 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstring>

int main(int ac, char *av[]){
    Harl karn;

	if (ac != 2){
		std::cout << "wrong number of args" << std::endl;
		return (0);
	}
	if (!strcmp(av[1], "")){
		std::cout << "arg is empty string" << std::endl;
	}
    karn.complain(av[1]);
}