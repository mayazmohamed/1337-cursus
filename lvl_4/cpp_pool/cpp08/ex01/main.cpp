/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:38:31 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/12 16:44:28 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main(){
    try
    {
        Span s(10);
    
        for (size_t i = 0; i < 10; i++)
        {
            s.addNumber(i);
        }
        std::cout << s.longestSpan() << std::endl;
        std::cout << s.shortestSpan() << std::endl;
        std::vector<int> numbers;
        numbers.push_back(11);
        numbers.push_back(21);
        numbers.push_back(31);
        numbers.push_back(41);
        numbers.push_back(51);
        numbers.push_back(61);
        s.rangeofiterators(numbers.begin(), numbers.end());
        std::cout << s.longestSpan() << std::endl;
        std::cout << s.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}