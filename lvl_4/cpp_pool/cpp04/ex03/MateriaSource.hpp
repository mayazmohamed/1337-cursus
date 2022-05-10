/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:49:53 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/07 16:30:43 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource
{
	AMateria* t[4];
public:
	MateriaSource();
	MateriaSource(MateriaSource &F);
	MateriaSource & operator=(const MateriaSource &F);
	virtual void learnMateria(AMateria* p);
	virtual AMateria* createMateria(std::string const & type);
	~MateriaSource();
};

#endif