/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:05:23 by momayaz           #+#    #+#             */
/*   Updated: 2022/06/03 15:41:13 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <string>

#include "iterator_traits.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"

template<class T>
class iterators
{
public:
    typedef std::size_t size_type;
	typedef typename ft::iterator_traits<T>::difference_type difference_type;
	typedef typename ft::iterator_traits<T>::value_type value_type;
	typedef typename ft::iterator_traits<T>::pointer pointer;
	typedef typename ft::iterator_traits<T>::reference reference;
	typedef typename ft::iterator_traits<T>::iterator_category iterator_category;
	
    iterators(/* args */){}
    ~iterators(){}
    iterators(pointer addr) : _ptr(addr){
    }
	iterators(const iterators &copy){
		*this = copy;
	}
    iterators & operator=(const iterators &assign){
	    if (this != &assign)
		    _ptr = assign._ptr;
	    return *this;
	}
    void operator++() {
        this._ptr++;
    }
    iterators operator++(int){
		iterators tmp = *this;
		this._ptr++;
		return tmp;
	}
    void operator--() {
        this._ptr--;
    }
    iterators operator--(int){
		iterators tmp = *this;
		this._ptr--;
		return tmp;
	}
    
	reference operator[](size_type index){
		return _ptr + index;
	}
	
	pointer operator->(){
		return _ptr;
	}
	
	reference operator*(){
		return *_ptr;
	}
	
	bool operator==(const iterators &F) const {
		return _ptr == F._ptr;
	}
	
	bool operator!=(const iterators &F) const {
		return _ptr != F._ptr;
	}
	
	bool operator<(const iterators &F) const {
		return _ptr < F._ptr;
	}
	
	bool operator<=(const iterators &F) const {
		return _ptr <= F._ptr;
	}
	
	bool operator>(const iterators &F) const {
		return _ptr > F._ptr;
	}
	
	bool operator>=(const iterators &F) const {
		return _ptr >= F._ptr;
	}
	
	long long operator-(const iterators &F){
		return (_ptr - F._ptr);
	}
	
	typename ft::enable_if<ft::is_integral<U>::value , iterators>::type operator+(const U& val){
		iterators tmp = *this;
		tmp._ptr += val;
		return tmp;
	}

	typename ft::enable_if<ft::is_integral<U>::value , iterators>::type operator-(const U& val){
		iterators tmp = *this;
		tmp._ptr -= val;
		return tmp;
	}
private:
    pointer _ptr;
	
};



template<class T>
class reverse_iterator
{
public:
    typedef std::size_t size_type;
	typedef typename ft::iterator_traits<T>::difference_type difference_type;
	typedef typename ft::iterator_traits<T>::value_type value_type;
	typedef typename ft::iterator_traits<T>::pointer pointer;
	typedef typename ft::iterator_traits<T>::reference reference;
	typedef typename ft::iterator_traits<T>::iterator_category iterator_category;
private:
    pointer _ptr;
public:
    reverse_iterator(/* args */){}
    ~reverse_iterator(){}
    reverse_iterator(pointer addr) : _ptr(addr){
    }
	reverse_iterator(const reverse_iterator &copy){
		*this = copy;
	}
    reverse_iterator & operator=(const reverse_iterator &assign){
	    if (this != &assign)
		    _ptr = assign._ptr;
	    return *this;
	}
    void operator++() {
        this._ptr--;
    }
    reverse_iterator operator++(int){
		reverse_iterator tmp = *this;
		this._ptr--;
		return tmp;
	}
    void operator--() {
        this._ptr++;
    }
    reverse_iterator operator--(int){
		reverse_iterator tmp = *this;
		this._ptr++;
		return tmp;
	}
    
	reference operator[](size_type index){
		return _ptr + index;
	}
	
	pointer operator->(){
		return _ptr;
	}
	
	reference operator*(){
		return *_ptr;
	}
	
	bool operator==(const reverse_iterator &F) const {
		return _ptr == F._ptr;
	}
	
	bool operator!=(const reverse_iterator &F) const {
		return _ptr != F._ptr;
	}
	
	bool operator<(const reverse_iterator &F) const {
		return _ptr < F._ptr;
	}
	
	bool operator<=(const reverse_iterator &F) const {
		return _ptr <= F._ptr;
	}
	
	bool operator>(const reverse_iterator &F) const {
		return _ptr > F._ptr;
	}
	
	bool operator>=(const reverse_iterator &F) const {
		return _ptr >= F._ptr;
	}
	
	long long operator-(const reverse_iterator &F){
		return (_ptr - F._ptr);
	}
	
	typename ft::enable_if<ft::is_integral<U>::value , iterators>::type operator+(const U& val){
		reverse_iterator tmp = *this;
		tmp._ptr += val;
		return tmp;
	}

	typename ft::enable_if<ft::is_integral<U>::value , iterators>::type operator-(const U& val){
		reverse_iterator tmp = *this;
		tmp._ptr -= val;
		return tmp;
	}
	
};


#endif