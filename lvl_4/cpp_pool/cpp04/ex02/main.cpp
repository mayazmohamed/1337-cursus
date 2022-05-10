/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:06:57 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/06 16:01:57 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>


int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Animal* animal[4];
	int x = 0;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	for (size_t i = 0; i < 2; i++)
		animal[i] = new Dog();
	for (size_t i = 2; i < 4; i++)
		animal[i] = new Cat();
	animal[x]->fill("houssam");
	animal[x]->fill("houssam");
	animal[x]->fill("houssam");
	animal[x]->fill("houssam");
	animal[x]->fill("houssam");
	animal[x]->readideas();
	
	for (size_t i = 0; i < 4; i++)
	{
		delete animal[i];
	}

	delete j;
	delete i;
	return 0;
}