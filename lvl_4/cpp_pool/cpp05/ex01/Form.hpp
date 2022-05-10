/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:44:49 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/10 13:52:24 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const name;
	bool s;
	int sign;
	int exec;

public:
	Form(std::string const name, bool s, int sign, int exec);
	Form();
	Form(Form &F);
	std::string getname()const;
	bool getbool()const;
	int getsign()const;
	int getexec()const;
	void beSigned(Bureaucrat &F);
	Form & operator=(const Form &F);
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
	~Form();
};

std::ostream& operator<< (std::ostream& out, const Bureaucrat& c);

#endif