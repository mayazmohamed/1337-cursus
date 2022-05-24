/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:23:57 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/17 15:16:42 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(/* args */)
{
	// std::cout << "Defult Cure constructor called" << std::endl;
	this->type = "cure";
}

Cure ::Cure(std::string const &type){
	this->type = type;
}

Cure::~Cure()
{
	// std::cout << "Defult Cure destructor called" << std::endl;
}

Cure:: Cure(Cure &F){
	std::cout << "Copy Cure constructor called" << std::endl;
	*this = F;
}

Cure & Cure:: operator=(const Cure &F){
	// std::cout  << "Copy assignment Cure constructor called" <<  std::endl;
	if (this != &F){
		*this = F;
	}
	return *this;
}

AMateria* Cure::clone()const{
	return new Cure();
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}