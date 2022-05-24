/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:47:43 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/18 11:40:27 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(){
	std::string name;
	std::string op;
	int grade;
	Form a("issam", 0, 5, 10);

	while (std::cin.good()){
		std::cout <<"pleas set name and grade" << std::endl;
		std::cout << "Bureaucrat name > " ;
		std::cin >> name;
		std::cout << "Bureaucrat grade > " ;
		std::cin >> grade;
		try
		{
			Bureaucrat b(name, grade);
			while (std::cin.good()){
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
				a.beSigned(b);
				// b.signForm(a);
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