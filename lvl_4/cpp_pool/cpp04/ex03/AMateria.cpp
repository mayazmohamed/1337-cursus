/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:25:36 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/17 15:16:23 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

void AMateria::settype(std::string type){
	this->type = type;
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::~AMateria()
{
	// std::cout << "Defult AMateria constructor called" << std::endl;
}

AMateria::AMateria()
{
	// std::cout << "Defult AMateria destructor called" << std::endl;
}

AMateria:: AMateria(AMateria &F){
	// std::cout << "Copy AMateria constructor called" << std::endl;
	*this = F;
}

AMateria & AMateria:: operator=(const AMateria &F){
	// std::cout  << "Copy assignment AMateria constructor called" <<  std::endl;
	if (this != &F){
		this->type = F.type;
	}
	return *this;
}

std::string  const & AMateria:: getType() const{
	return this->type;
}

void AMateria:: use(ICharacter& target){
	std::cout << &target;
}