/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:51:40 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/06 13:06:33 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
public:
	Dog();
	Dog(Dog &F);
	Dog & operator=(const Dog &F);
	virtual void makeSound()const ;
	virtual ~Dog();
};


#endif