/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:17:39 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/16 13:32:09 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>



class ClapTrap
{
	protected:
		std::string name;
		int HP;
		int EP;
		int AD;
	public:
		ClapTrap();
		ClapTrap(std::string &name);
		ClapTrap(const ClapTrap &F);
		ClapTrap &operator = (const ClapTrap &F);
		std::string getname() const;
		int getHP() const;
		int getEP() const;
		int getAD() const;
		void setname(std::string name);
		void setHP(int HP);
		void setEP(int EP);
		void setAD(int AD);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		~ClapTrap();
};



#endif