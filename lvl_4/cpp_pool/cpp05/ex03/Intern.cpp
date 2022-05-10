/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:53:07 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/10 20:26:59 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Constructors
Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}


// Destructor
Intern::~Intern()
{
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}


// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}

Form* Intern::makeForm(std::string str1, std::string str2){
	int x;

	Form *f[3] = {
		new ShrubberyCreationForm(str2),
		new RobotomyRequestForm(str2),
		new PresidentialPardonForm(str2)
	};
	std::string t[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};
	for (x = 0; x < 3; x++){
		if (t[x] == str1)
			break;
	}
	if (x == 3){
		std::cout << "form not found" << std::endl;
		return NULL;
	}
	std::cout << "Intern creates "<< str1 << std::endl;
	for (int i = 0; i < 3; i++){
		if (i != x)
			delete f[i];
	}
	return f[x];
}