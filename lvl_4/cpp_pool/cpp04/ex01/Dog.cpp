/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:51:43 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/06 15:28:47 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Defult Dog constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Defult Dog destructor called" << std::endl;
	delete this->brain;
}

Dog:: Dog(Dog &F){
	std::cout << "Copy Dog constructor called" << std::endl;
	*this = F;
}

Dog & Dog:: operator=(const Dog &F){
	std::cout  << "Copy assignment Dog constructor called" <<  std::endl;
	if (this != &F){
		this->type = F.type;
	}
	return *this;
}

void Dog:: makeSound()const{
	std::cout << "Woof Woof" << std::endl;
}

int Dog::getin()const{
	return this->in;
}

void Dog::setin(int in){
	this->in = in;
}

void Dog:: fill(std::string idea){
	if(this->getin() < 100){
		this->brain->setidea(idea, this->getin());
		this->setin(this->getin() + 1);
	}
	else
		std::cout << "you can't set more then 100 ideas" << std::endl;
}

void Dog::readideas(){
	for (int i = 0; i < this->getin(); i++)
		std:: cout << this->brain->getidea(i) << std::endl;

}