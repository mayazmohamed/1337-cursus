/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:47:43 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/10 20:32:53 by momayaz          ###   ########.fr       */
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
	std::string name;
	std::string op;
	ShrubberyCreationForm f("sh");
	RobotomyRequestForm r("ro");
	PresidentialPardonForm p("pr");
	Bureaucrat M("momayaz", 5);
    Bureaucrat I("izouf", 5);
	int grade;


	while (1){
		std::cout <<"pleas set name and grade" << std::endl;
		std::cout << "Bureaucrat name > " ;
		std::cin >> name;
		if (name == "Exit")
			break;
		std::cout << "Bureaucrat grade > " ;
		std::cin >> grade;
		try
		{
			Bureaucrat b(name, grade);
			while (1){
				std::cout << b << std::endl;
				std::cout << "****************************" << std::endl;
				std::cout << "* 1: Incriment             *" << std::endl;
				std::cout << "* 2: Decrement             *" << std::endl;
				std::cout << "* Exit: set new Bureaucrat *" << std::endl;
				std::cout << "****************************" << std::endl;
				std::cout << "youre option please: >> ";
				std::cin >> op;
				std::cout << std::endl;
				if (op == "1"){
					b.increment();
				}
				else if (op == "2"){
					b.decrement();
				}
				else if (op == "Exit"){
					break;
				}
				else{
					std::cout << "wrong option try again " << std::endl;
				}
				std::cout << M << std::endl;
				f.beSigned(M);
				f.execute(I);
				r.beSigned(M);
				r.execute(I);
				p.beSigned(M);
				p.execute(I);
				Form* f;
				Intern in;
				f = in.makeForm("ShrubberyCreationForm", "hey");
			}

		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}


	}

	// Bureaucrat A("A", 5);
	// Bureaucrat B("B", 9);
	// Form F("F", 0, 5, 10);


	// // F.beSigned(B);
	// F.beSigned(A);
	// // B.signForm(F);
}