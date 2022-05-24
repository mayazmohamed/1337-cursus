/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:57:39 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/24 12:22:09 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>

int main(){
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << "++++++++++++++++++++++++++++++++++" << std::endl;
    {
        std::vector<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back()  << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        //[...]
        mstack.push_back(0);
        std::vector<int>::iterator it = mstack.begin();
        std::vector<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
    }
    std::cout << "++++++++++++++++++++++++++++++++++" << std::endl;
    {
        MutantStack<int> gquiz;
        gquiz.push(1);
        gquiz.push(2);
        gquiz.push(3);
        gquiz.push(4);
        gquiz.push(5);
        gquiz.push(6);
        
        try
        {
            for (MutantStack<int>::iterator i = gquiz.begin(); i < gquiz.end() ; i++)
                 std::cout << *i << std::endl;
            std::cout << "++++++++++++++++++++++++++++++++++" << std::endl;
            for (MutantStack<int>::r_iterator i = gquiz.rbegin(); i < gquiz.rend() ; i++)
                 std::cout << *i << std::endl;      
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}