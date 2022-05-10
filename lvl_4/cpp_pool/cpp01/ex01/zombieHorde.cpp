/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:22:28 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/29 14:57:46 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde( int N, std::string name ){
	Zombie* zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++){
		zombieHorde[i].Zomb(name);
		zombieHorde[i].announce();
	}
	return (zombieHorde);
}