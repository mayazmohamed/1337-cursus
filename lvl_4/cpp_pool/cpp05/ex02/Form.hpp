/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:44:49 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/10 18:51:42 by momayaz          ###   ########.fr       */
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
	const int sign;
	const int exec;

public:
	Form(std::string const name, bool s, int sign, int exec);
	Form();
	Form(Form &F);
	Form & operator=(const Form &F);
	virtual std::string getname()const;
	bool getbool()const;
	int getsign()const;
	int getexec()const;
	void beSigned(Bureaucrat &F);
	virtual void execute(Bureaucrat const & executor)const = 0;
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