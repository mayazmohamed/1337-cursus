/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:50:58 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/07 16:29:24 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Character_HPP
#define Character_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter
{
private:
	AMateria* inv[4];
	std::string name;
public:
	Character();
	Character(std::string const &type);
	Character(Character &F);
	Character & operator=(const Character &F);
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
	~Character();
};

#endif