/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:51:40 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/06 14:55:48 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
private:
	Brain* brain;
	int in;
public:
	Dog();
	Dog(Dog &F);
	Dog & operator=(const Dog &F);
	virtual void makeSound()const ;
	virtual int getin()const;
	virtual void setin(int in);
	virtual void fill(std::string idea);
	virtual void readideas();
	std::string getidea(int id)const;
	void setidea(std::string idea, int id);
	virtual ~Dog();
};


#endif