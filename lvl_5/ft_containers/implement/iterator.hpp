/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:05:23 by momayaz           #+#    #+#             */
/*   Updated: 2022/07/25 14:18:19 by momayaz          ###   ########.fr       */
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
        this->_ptr++;
    }
    iterators operator++(int){
		iterators tmp = *this;
		this->_ptr++;
		return tmp;
	}
    void operator--() {
        this->_ptr--;
    }
    iterators operator--(int){
		iterators tmp = *this;
		this->_ptr--;
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
	

	template<class U>
	typename ft::enable_if<ft::is_integral<U>::value , iterators>::type operator+(const U& val){
		iterators tmp = *this;
		tmp._ptr += val;
		return tmp;
	}

	template<class U>
	typename ft::enable_if<ft::is_integral<U>::value , iterators>::type operator-(const U& val){
		iterators tmp = *this;
		tmp._ptr -= val;
		return tmp;
	}
	pointer base() const{
		return _ptr;
	}
private:
    pointer _ptr;
	
};



template<class Iterator>
class reverse_iterator
{
public:
    typedef std::size_t size_type;
	typedef Iterator iterator_type;
	typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
	typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
	typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
	typedef typename ft::iterator_traits<iterator_type>::reference reference;
	typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
private:
    iterator_type _ptr;
public:
    reverse_iterator(/* args */){}
    reverse_iterator (iterator_type it){
		_ptr = it;
	}
	template <class Iter>
  	reverse_iterator (const reverse_iterator<Iter>& rev_it){
		_ptr = rev_it._ptr;
	}
    reverse_iterator & operator=(const reverse_iterator &assign){
	    if (this != &assign)
		    _ptr = assign._ptr;
	    return *this;
	}

	iterator_type base() const {
		return _ptr.base();
	}
	reference operator*(){
		return *(_ptr.base() - 1);
	}
	reverse_iterator operator+ (difference_type n) const {
		return reverse_iterator(_ptr - n);
	}
	reverse_iterator operator- (difference_type n) const {
		return reverse_iterator(_ptr + n);
	}
	reverse_iterator & operator++(){
		_ptr--;
		return *this;
	}
	reverse_iterator operator++(int){
		reverse_iterator tmp = *this;
		_ptr--;
		return tmp;
	}
	reverse_iterator & operator--(){
		_ptr++;
		return *this;
	}
	reverse_iterator operator--(int){
		reverse_iterator tmp = *this;
		_ptr++;
		return tmp;
	}
	reference operator[](size_type index){
		return _ptr.base()[-index];
	}
	pointer operator->(){
		return _ptr.base() - 1;
	}
	reverse_iterator& operator+= (difference_type n){
		_ptr -= n;
		return *this;
	}
	reverse_iterator& operator-= (difference_type n){
		_ptr += n;
		return *this;
	}
	
	
};

template <class Iterator>
  bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
	  return lhs.base() == rhs.base();
  }
  template <class Iterator>
  bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
	  return lhs.base() != rhs.base();
  }
  template <class Iterator>
  bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
	  return lhs.base() > rhs.base();
  }
  template <class Iterator>
  bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
	  return lhs.base() >= rhs.base();
  }
  template <class Iterator>
  bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
	  return lhs.base() < rhs.base();
  }
  template <class Iterator>
  bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
	  return lhs.base() <= rhs.base();
  }
  template <class Iterator>
  typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
	  return rhs.base() - lhs.base();
  }
  template <class Iterator>
  reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rhs){
	  return reverse_iterator<Iterator>(rhs.base() - n);
  }


#endif