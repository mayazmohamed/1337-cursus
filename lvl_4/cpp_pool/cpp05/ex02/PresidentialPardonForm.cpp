/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:21:47 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/18 12:31:55 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardonForm", 0, 25, 5)
{
	this->target = "default";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm:: PresidentialPardonForm(PresidentialPardonForm &F){
	std::cout << "Copy PresidentialPardonForm constructor called" << std::endl;
	*this = F;
}

PresidentialPardonForm & PresidentialPardonForm:: operator=(const PresidentialPardonForm &F){
	std::cout  << "Copy assignment PresidentialPardonForm constructor called" <<  std::endl;
	(void)F;
	return *this;
}

void PresidentialPardonForm:: execute(Bureaucrat const & executor) const{
	if (this->getbool() != true){
		std::cout << "is not signed 3 " << std::endl;
		return;
	}
	if (executor.getGrade() > this->getexec()){
		throw GradeTooLowException();
	}
	if (executor.getGrade() < 1)
		throw GradeTooHighException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::	PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", 0, 25, 5){
	this->target = target;
}
