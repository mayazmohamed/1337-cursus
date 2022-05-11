/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:20:16 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/11 16:32:32 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void){
    srand(time(NULL));
    int x = rand() % 3;
    
    if (x == 0)       
        return new A();
    else if (x == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p){
    A *a;
    B *b;
    C *c;
    
    if ((a = dynamic_cast<A*>(p)))
        std::cout << "Type A" << std::endl;
    else if ((b = dynamic_cast<B*>(p)))
        std::cout << "Type B" << std::endl;
    else if ((c = dynamic_cast<C*>(p)))
        std::cout << "Type C" << std::endl;
} 

void identify(Base& p){    
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Type A" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Type B" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Type C" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }

} 


int main(){

    Base *b;
    
    b = generate();
    identify(b); 
    identify(*b); 
}