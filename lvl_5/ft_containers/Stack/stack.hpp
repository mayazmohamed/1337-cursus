/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:57:46 by momayaz           #+#    #+#             */
/*   Updated: 2022/06/13 16:58:39 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP


#include <iostream>
#include <string>
#include "../vector/vector.hpp"




namespace ft{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
    public:
        typedef T value_type;
		typedef Container container_type;
		typedef std::size_t size_type;

		template <class U, class V>
		friend bool operator== (const stack<U,V>& lhs, const stack<U,V>& rhs);
		template <class U, class V>
		friend bool operator!= (const stack<U,V>& lhs, const stack<U,V>& rhs);
		template <class U, class V>
		friend bool operator< (const stack<U,V>& lhs, const stack<U,V>& rhs);
		template <class U, class V>
		friend bool operator<= (const stack<U,V>& lhs, const stack<U,V>& rhs);
		template <class U, class V>
		friend bool operator> (const stack<U,V>& lhs, const stack<U,V>& rhs);
		template <class U, class V>
		friend bool operator>= (const stack<U,V>& lhs, const stack<U,V>& rhs);
        explicit stack (const container_type& ctnr = container_type()){
            sk = ctnr;
        }

        bool empty() const{
           return sk.empty();
        }

        size_type size() const{
            return sk.size();
        }

        value_type& top(){
            return sk.back();
        }

        const value_type& top() const{
            return sk.back();
        }

        void push (const value_type& val){
            sk.push_back(val);
        }

        void pop(){
            sk.pop_back();
        }

    private:
        container_type sk;
    };
    
    template <class T, class Container>
  	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		  return lhs.sk == rhs.sk;
	}

	template <class T, class Container>
  	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		  return lhs.sk != rhs.sk;
	}

	template <class T, class Container>
  	bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		  return lhs.sk < rhs.sk;
	}

	template <class T, class Container>
  	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		  return lhs.sk <= rhs.sk;
	}

	template <class T, class Container>
  	bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		  return lhs.sk > rhs.sk;
	}

	template <class T, class Container>
  	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		  return lhs.sk >= rhs.sk;
	}

    
}








#endif