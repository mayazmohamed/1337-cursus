/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:14:25 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/06 15:34:49 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(std::string type);
	void setType(std::string type);
	std::string getType() const;
	Animal(Animal &F);
	Animal & operator=(const Animal &F);
	virtual void makeSound() const = 0;
	virtual ~Animal();
	virtual int getin()const;
	virtual void setin(int in);
	virtual void fill(std::string idea);
	virtual void readideas();
};



#endif