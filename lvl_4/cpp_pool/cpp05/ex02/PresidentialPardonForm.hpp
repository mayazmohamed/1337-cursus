/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:21:29 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/10 18:45:53 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARADONFORM_HPP
#define PRESIDENTIALPARADONFORM_HPP
#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	std::string target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm &F);
	Bureaucrat const & executor();
	PresidentialPardonForm & operator=(const PresidentialPardonForm &F);
	void execute(Bureaucrat const & executor) const;
	~PresidentialPardonForm();
};



#endif