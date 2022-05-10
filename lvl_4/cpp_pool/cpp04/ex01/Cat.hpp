/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:05:03 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/06 15:24:36 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
private:
	Brain* brain;
	int in;
public:
	Cat();
	Cat(Cat &F);
	Cat & operator=(const Cat &F);
	virtual void makeSound()const;
	virtual int getin()const;
	virtual void setin(int in);
	virtual void fill(std::string idea);
	virtual void readideas();
	std::string getidea(int id)const;
	void setidea(std::string idea, int id);
	virtual ~Cat();
};

#endif