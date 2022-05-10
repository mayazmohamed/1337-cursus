/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 10:27:39 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/10 13:52:45 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREACRAT_HPP
#define BUREACRAT_HPP

#include <iostream>
#include<exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string const name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat &F);
	Bureaucrat & operator=(const Bureaucrat &F);
	std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();
	Form signForm(Form &b);
	~Bureaucrat();
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("The grade you set is too high");
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("The grade you set is too low");
		}
	};

};
std::ostream& operator<< (std::ostream& out, const Bureaucrat& c);



#endif