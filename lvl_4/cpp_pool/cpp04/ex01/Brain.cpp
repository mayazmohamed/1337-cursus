/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:44:58 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/06 14:34:10 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

void Brain::setidea(std::string idea, int id){
	this->ideas[id] = idea;
}

std::string Brain:: getidea(int id) const{
	return this->ideas[id];
}

Brain::Brain()
{
	std::cout << "Defult Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
			this->ideas[i] = "";
}

Brain::~Brain()
{
	std::cout << "Defult Brain destructor called" << std::endl;
}

Brain:: Brain(Brain &F){
	std::cout << "Copy Brain constructor called" << std::endl;
	*this = F;
}

Brain & Brain:: operator=(const Brain &F){
	std::cout  << "Copy assignment Brain constructor called" <<  std::endl;
	if (this != &F){
		for (int i = 0; i < 100; i++)
			this->ideas[i] = F.ideas[i];

	}
	return *this;
}
