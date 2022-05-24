/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:05:06 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/17 14:28:09 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat()
{
	std::cout << "Defult Cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
	this->in = 0;
}

Cat::~Cat()
{
	std::cout << "Defult Cat destructor called" << std::endl;
	delete this->brain;
}

Cat:: Cat(Cat &F){
	this->brain = new Brain();
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = F;
}

Cat & Cat:: operator=(const Cat &F){
	std::cout  << "Copy assignment Cat constructor called" <<  std::endl;
	if (this != &F){
		this->type = F.type;
		*this->brain = *F.brain;
	}
	return *this;
}

void Cat:: makeSound()const{
	std::cout << "Meow Meow" << std::endl;
}

int Cat::getin()const{
	return this->in;
}

void Cat::setin(int in){
	this->in = in;
}

void Cat:: fill(std::string idea){
	if(this->getin() < 100){
		this->brain->setidea(idea, this->getin());
		this->setin(this->getin() + 1);
	}
	else
		std::cout << "you can't set more then 100 ideas" << std::endl;
}

void Cat::readideas(){
	for (int i = 0; i < this->getin(); i++)
		std:: cout << this->brain->getidea(i) << std::endl;

}
