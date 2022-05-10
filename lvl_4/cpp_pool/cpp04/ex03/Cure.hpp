/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:32:19 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/07 16:23:54 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria
{
public:
	Cure();
	Cure(std::string const &type);
	Cure(Cure &F);
	Cure & operator=(const Cure &F);
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
	~Cure();
};



#endif