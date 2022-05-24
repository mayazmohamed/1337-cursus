/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:43:50 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/13 11:43:49 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void randomChump( std::string name ){
	Zombie* hdrabi;
	hdrabi = newZombie(name);
	hdrabi->announce();
	delete hdrabi;
}