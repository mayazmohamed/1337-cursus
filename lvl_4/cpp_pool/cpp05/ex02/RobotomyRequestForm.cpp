/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:21:51 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/18 12:31:49 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequestForm", 0, 72, 45)
{
	this->target = "default";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}


RobotomyRequestForm:: RobotomyRequestForm(RobotomyRequestForm &F){
	std::cout << "Copy RobotomyRequestForm constructor called" << std::endl;
	*this = F;
}

RobotomyRequestForm & RobotomyRequestForm:: operator=(const RobotomyRequestForm &F){
	std::cout  << "Copy assignment RobotomyRequestForm constructor called" <<  std::endl;
	(void)F;
	return *this;
}

void RobotomyRequestForm:: execute(Bureaucrat const & executor) const{
	if (this->getbool() != true){
		std::cout << "is not signed 2 " << std::endl;
		return;
	}
	if (executor.getGrade() > this->getexec()){
		throw GradeTooLowException();
	}
	if (executor.getGrade() < 1)
		throw GradeTooHighException();
	srand(time(NULL));
	if (rand() % 2){
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	}
	else
		std::cout << " the robotomy failed" << std::endl;
}

RobotomyRequestForm::	RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 0, 72, 45){
	this->target = target;
}
