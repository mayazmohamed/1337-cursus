/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:55:52 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/11 19:55:54 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main( void ) {

    Array<int>			intArray;
	Array<std::string>	stringArray(10);
	Array<std::string>	otherStringArray;

	stringArray[0] = "Hi";
	stringArray[1] = "Hello";
	stringArray[2] = "How are you?";
	stringArray[3] = "Fine and you?";
	stringArray[4] = "Doing great thanks!";
	stringArray[5] = "You're very welcome";
	std::cout << "intArray.size() = " << intArray.size() << std::endl;
	std::cout << "stringArray.size() = " << stringArray.size() << std::endl;
	otherStringArray = stringArray;
	otherStringArray[3] = "I'm good, how about you?";

	try
	{
		std::cout << stringArray[59] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << stringArray[-3] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    { 
        // Array<std::string>	test;
        // test = stringArray;
        // test[2] = "haha";
        // std::cout << stringArray[2] << std::endl;
        // std::cout << test[2] << std::endl;
    }
    { 
        Array<std::string>	test(stringArray);
        test[2] = "haha";
        std::cout << stringArray[2] << std::endl;
        std::cout << test[2] << std::endl;
    }


	return 0;
}