/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:06:16 by momayaz           #+#    #+#             */
/*   Updated: 2022/07/13 15:17:40 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <string.h>
#include <stdexcept>



#include "../red_black_tree/red_black_tree.hpp"
#include "../implement/pair.hpp"
#include "../implement/enable_if.hpp"
#include "../implement/iterator.hpp"
#include "../implement/lexicographical_compare.hpp"
#include "../implement/equal.hpp"
#include "../implement/is_integral.hpp"




namespace ft{
    
    template < class Key, class T, class Compare = std::less<Key>,  class Alloc = std::allocator<ft::pair<const Key,T> > >
    class map{
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef std::pair<const key_type, mapped_type> value_type;
            typedef Compare key_compare;
            typedef Alloc allocator_type;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::size_type size_type;
            typedef typename allocator_type::difference_type difference_type;
            

            typedef iteratorRBT<iterator> iterator;
            
    };

    
};


#endif 