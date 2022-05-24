/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:47:43 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/18 12:58:03 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main(){
	Bureaucrat M("momayaz", 5);
        Bureaucrat I("izouf", 26);
        Form *F;
        Intern In;
        (void)M;
        (void)I;
        (void)F;
        (void)I;

        try
        {
             F = In.makeForm("presidential pardon", "home");
			if (F == nullptr)
				return 0;
            std::cout << M << std::endl;
            std::cout << I << std::endl;
            F->beSigned(M);
            F->execute(M);
            std::cout << M << std::endl;
            delete F;
        }
        catch(const std::exception& e)
        {
            delete F;
            std::cerr << e.what() << '\n';
        }
}