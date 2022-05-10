/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:41:45 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/10 18:34:25 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::ostream& operator<< (std::ostream& out, const Bureaucrat& c){
	return out << c.getName() << ", bureaucrat grade " << c.getGrade();
}

std::string Bureaucrat::getName() const{
	return this->name;
}

int Bureaucrat::getGrade() const{
	return this->grade;
}

Bureaucrat:: Bureaucrat(Bureaucrat &F){
	std::cout << "Copy Bureaucrat constructor called" << std::endl;
	*this = F;
}

Bureaucrat & Bureaucrat:: operator=(const Bureaucrat &F){
	std::cout  << "Copy assignment Bureaucrat constructor called" <<  std::endl;
	if (this != &F){
		this->grade = F.grade;
	}
	return *this;
}

void Bureaucrat::increment(){
	if (this->grade == 1){
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade -= 1;
}

void Bureaucrat::decrement(){
	if (this->grade == 150){
		throw Bureaucrat::GradeTooLowException();
	}
	this->grade += 1;
}

Bureaucrat:: Bureaucrat(std::string name, int grade): name(name){
	if (grade > 150){
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade < 1){
		throw Bureaucrat::GradeTooHighException();
	}
	else{
		this->grade = grade;
	}
}

Bureaucrat::Bureaucrat()
{
	std::cout << "Defult constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Defult destructor called" << std::endl;
}

void Bureaucrat::signForm(Form &b){
	if (b.getbool() == true){
		std::cout << b.getname() << " is already signed " << std::endl;
		return;
	}
	if (this->getGrade() > b.getsign())
		throw GradeTooLowException();
	else if (this->getGrade() <= 0)
		throw GradeTooHighException();
	else if (this->getGrade() <= b.getsign()) {
		std::cout << this->getName() << " signed " << b.getname() << std::endl;
		return;
	}
	std::cout << this->getName() << " couldn’t sign " << b.getname() << " because is not including in sign form" << std::endl;
}

void Bureaucrat::executeForm(Form const & b){
	if (b.getbool() == true){
		if (this->getGrade() > b.getexec())
			throw GradeTooLowException();
		else if (this->getGrade() <= 0)
			throw GradeTooHighException();
		else if (this->getGrade() <= b.getexec()) {
			std::cout << this->getName() << " executed " << b.getname() << std::endl;
		}
	}
	else
		std::cout << this->getName() << " couldn’t executed " << b.getname() << " because is not including in sign form" << std::endl;
}
