/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:48:22 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/07 16:23:18 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria
{
public:
	Ice();
	Ice(std::string const &type);
	Ice(Ice &F);
	Ice & operator=(const Ice &F);
	virtual void use(ICharacter& target);
	virtual AMateria* clone() const;
	~Ice();
};

#endif