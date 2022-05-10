/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:26:03 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/29 15:45:29 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(){
	std::string brain = "HI THIS IS BRAIN";
	std::string* ptr = &brain;
	std::string ref = brain;
	std::cout << "The memory address of the string variable is: > " << &brain << std::endl;
	std::cout << "The memory address held by stringPTR is: > " << &ptr << std::endl;
	std::cout << "The memory address held by stringREF is: > " << &ref << std::endl;
	std::cout << "The value of the string variable is: > " << brain << std::endl;
	std::cout << "The value pointed to by stringPTR is: > " << ptr << std::endl;
	std::cout << "The value pointed to by stringREF is: > " << ref << std::endl;
}