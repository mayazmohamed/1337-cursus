/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:25:38 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/17 15:01:54 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIA_HPP
#define IMATERIA_HPP
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string type;
public:
	AMateria();
	AMateria(std::string const &type);
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
	AMateria(AMateria &F);
	AMateria & operator=(const AMateria &F);
	void settype(std::string type);
	void setname(std::string name);
	virtual ~AMateria();
};

#endif