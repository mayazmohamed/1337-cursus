/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:46:43 by momayaz           #+#    #+#             */
/*   Updated: 2022/07/28 10:50:48 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <string.h>
#include <set>
#include <stdexcept>



#include "../red_black_tree/red_black_tree.hpp"
#include "../implement/pair.hpp"
#include "../implement/enable_if.hpp"
#include "../implement/iterator.hpp"
#include "../implement/lexicographical_compare.hpp"
#include "../implement/equal.hpp"
#include "../implement/is_integral.hpp"

namespace ft{
    

    template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> > class set
    {
        public :
            typedef T key_type;
            typedef T value_type;
            typedef Compare key_compare;
            typedef Compare value_compare;
            typedef Alloc allocator_type;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename RedBlackTree<value_type, key_compare, allocator_type>::iterator iterator;
            typedef typename RedBlackTree<value_type, key_compare, allocator_type>::const_iterator const_iterator;
            typedef typename RedBlackTree<value_type, key_compare, allocator_type>::reverse_iterator reverse_iterator;
            typedef typename RedBlackTree<value_type, key_compare, allocator_type>::const_reverse_iterator const_reverse_iterator;
            typedef std::ptrdiff_t difference_type;
            typedef std::size_t size_type;

        private :
            typedef RedBlackTree<value_type, value_compare, allocator_type> RBT;
            RBT _tree;
            allocator_type _alloc;
            key_compare _comp;

        public :

            // *************************************** Constructor *************************************** //
            explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc), _alloc(alloc), _comp(comp) {}
    
            template <class InputIterator>
            set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc), _alloc(alloc), _comp(comp)
            {
                for (; first != last; first++)
                    _tree.insert(*first);
            }

            set (const set& x){
                *this = x;
            }


            // *************************************** Assign *************************************** //
            set& operator= (const set& x){
                if (this != &x) {
                    _tree = x._tree;
                    _alloc = x._alloc;
                    _comp = x._comp;
                }
                return *this;
            }


            // *************************************** Destructor *************************************** //
            ~set (){
            }


            // *************************************** Iterators *************************************** //
            iterator begin() {
                return iterator(_tree.begin());
            }

            const_iterator begin() const {
                return const_iterator(_tree.begin());
            }

            iterator end() {
                return iterator(NULL);
            }

            const_iterator end() const {
                return const_iterator(NULL);
            }

            reverse_iterator rbegin() {
                return reverse_iterator(_tree.end());
            }

            const_reverse_iterator rbegin() const {
                return const_reverse_iterator(_tree.end());
            }

            reverse_iterator rend() {
                return reverse_iterator(NULL);
            }

            const_reverse_iterator rend() const {
                return const_reverse_iterator(NULL);
            }


            // *************************************** Capacity *************************************** //
            bool empty() const {
                return _tree.size() == 0;
            }

            size_type size() const {
                return _tree.size();
            }

            size_type max_size() const {
                return _tree.max_size();
            }


            // *************************************** Modifiers *************************************** //
            ft::pair<iterator,bool> insert (const value_type& val) {
                typename RBT::nodePtr node = _tree.find(val);

                bool inserted = false;
                if (!node) {
                    _tree.insert(val);
                    inserted = true;
                    node = _tree.find(val);
                }
                return ft::pair<iterator,bool>(iterator(node), inserted);
            }

            iterator insert (iterator position, const value_type& val) {
                (void)position;
                typename RBT::nodePtr node = _tree.find(val);

                if (!node) {
                    _tree.insert(val);
                    node = _tree.find(val);
                }
                return iterator(node);
            }

            template <class InputIterator>
            void insert (InputIterator first, InputIterator last) {
                
                typename RBT::nodePtr node;
                
                for (; first != last; first++) {
                    node = _tree.find(*first);
                    if (!node)
                        _tree.insert(*first);
                }
            }

            void erase (iterator position) {
                _tree.deleteNode(*position);
            }

            size_type erase (const value_type& val) {
                typename RBT::nodePtr node = _tree.find(val);
                if (node) {
                    _tree.deleteNode(val);
                    return 1;
                }
                return 0;
            }

            void erase (iterator first, iterator last) {
                while (first != last) {
                    erase(first++);
                }
            }

            void swap (set& x) {
                set tmp = x;
                x = *this;
                *this = tmp;
            }

            void clear() {
                _tree.freeTree();
            }


            // *************************************** Observers *************************************** //
            value_compare value_comp() const {
                return _comp;
            }

            key_compare key_comp() const {
                return _comp;
            }


            // *************************************** Operations *************************************** //
            iterator find (const value_type& val) const {
                typename RBT::nodePtr node = _tree.find(val);                
                if (node)
                    return iterator(node);
                return end();
            }

            size_type count (const value_type& val) const {
                typename RBT::nodePtr node = _tree.find(val);
                return node ? 1 : 0;
            }

            iterator lower_bound (const value_type& val) const {
                typename RBT::nodePtr tmp = _tree.getRoot();
                typename RBT::nodePtr node = NULL;

                while (tmp != _tree.getNull()) {
                    if (_comp(tmp->value, val))
                        tmp = tmp->right;
                    else
                    {
                        node = tmp;
                        tmp = tmp->left;
                    }
                }
                return iterator(node);
            }

            iterator upper_bound (const value_type& val) const {
                typename RBT::nodePtr tmp = _tree.getRoot();
                typename RBT::nodePtr node = NULL;

                while (tmp != _tree.getNull()) {
                    if (_comp(val, tmp->value)) {
                        node = tmp;
                        tmp = tmp->left;
                    }
                    else
                    {
                        tmp = tmp->right;
                    }
                }
                return iterator(node);
            }

            ft::pair<iterator,iterator> equal_range (const value_type& val) {
                return ft::pair<iterator,iterator>(lower_bound(val), upper_bound(val));
            }

            // *************************************** Allocator *************************************** //
            allocator_type get_allocator() const {
                return _alloc;
            }
    };
}


#endif