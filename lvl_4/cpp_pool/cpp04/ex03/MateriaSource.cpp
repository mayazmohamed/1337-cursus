/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:21:41 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/07 17:09:35 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
	std::cout << "Defult MateriaSource constructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		this->t[i] = nullptr;
	}

}

MateriaSource::~MateriaSource()
{
	std::cout << "Defult MateriaSource destructor called" << std::endl;
}

MateriaSource:: MateriaSource(MateriaSource &F){
	std::cout << "Copy MateriaSource constructor called" << std::endl;
	*this = F;
}

MateriaSource & MateriaSource:: operator=(const MateriaSource &F){
	std::cout  << "Copy assignment MateriaSource constructor called" <<  std::endl;
	if (this != &F)
		*this = F;
	return *this;
}

void MateriaSource:: learnMateria(AMateria* p){
	for (size_t i = 0; i < 4; i++)
		if (this->t[i] == nullptr){
			t[i] = p;
			return;
		}
	std::cout << "you can't set more then 4 materia" << std::endl;
}

AMateria* MateriaSource:: createMateria(std::string const & type){
	if (type != "ice" && type != "cure")
		return 0;
	for (size_t i = 0; i < 4; i++)
		if(this->t[i]->getType() == type)
			return this->t[i]->clone();
	return 0;
}