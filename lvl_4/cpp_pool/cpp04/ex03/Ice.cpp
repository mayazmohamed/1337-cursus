/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:23:22 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/07 17:07:58 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"


Ice::Ice(/* args */)
{
	std::cout << "Defult Ice constructor called" << std::endl;
	this->type = "ice";
}

Ice ::Ice(std::string const &type){
	this->type = type;
}

Ice::~Ice()
{
	std::cout << "Defult Ice destructor called" << std::endl;
}

Ice:: Ice(Ice &F){
	std::cout << "Copy Ice constructor called" << std::endl;
	*this = F;
}

Ice & Ice:: operator=(const Ice &F){
	std::cout  << "Copy assignment Ice constructor called" <<  std::endl;
	if (this != &F)
		*this = F;
	return *this;
}

AMateria* Ice::clone()const{
	return new Ice();
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}