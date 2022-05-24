/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:38:31 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/24 12:08:29 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main(){
    try
    {
        Span s(10);
    
        for (size_t i = 0; i < 5; i++)
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

// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }