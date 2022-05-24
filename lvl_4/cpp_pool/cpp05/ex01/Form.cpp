/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:44:45 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/18 11:45:29 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form ::Form(std::string const name, bool s, int sign, int exec): name(name), sign(sign), exec(exec){
	if (sign < 1 || exec < 1)
		throw GradeTooHighException();
	if (sign > 150 || exec > 150)
		throw GradeTooLowException();
	this->s = s;
}

void Form::beSigned(Bureaucrat &F){
	if (F.getGrade() > this->sign)
		throw GradeTooLowException();
	else if (F.getGrade() <= 0)
		throw GradeTooHighException();
	else{
		F.signForm(*this);
		this->s = true;
	}
}

Form::Form(): name(""), sign(150), exec(150)
{
	this->s = 0;
}

Form::~Form()
{
}

Form:: Form(Form &F): sign(150), exec(150){
	std::cout << "Copy Form constructor called" << std::endl;
	*this = F;
}

Form & Form:: operator=(const Form &F){
	std::cout  << "Copy assignment Form constructor called" <<  std::endl;
	if (this != &F){
		this->s = F.s;
	}
	return *this;
}

std::string Form:: getname()const{
	return this->name;
}

bool Form:: getbool()const{
	return (this->s);
}

int Form:: getsign()const{
	return this->sign;
}

int Form:: getexec()const{
	return this->exec;
}

std::ostream& operator<< (std::ostream& out, const Form& c){
	return out << c.getname() << " it is signed -> " << c.getbool() << " grade required to sign it -> " << c.getsign() << "  grade required to execute it -> " << c.getexec() << std::endl;
}