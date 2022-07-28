/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:06:16 by momayaz           #+#    #+#             */
/*   Updated: 2022/07/27 14:16:38 by momayaz          ###   ########.fr       */
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
            
            class value_compare;
            typedef Key key_type;
            typedef T mapped_type;
            typedef ft::pair<const key_type, mapped_type> value_type;
            typedef Compare key_compare;
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
            
            /******************************************** (constructor)******************************************/
            
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(value_compare(comp), alloc), _alloc(alloc), _comp(comp) {}
            
            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _tree(value_compare(comp), alloc), _alloc(alloc), _comp(comp){
                for (; first != last; first++)
                {
                    _tree.insert(*first);
                }
                
            }

            map (const map& x){
                *this = x;
            }

            map& operator=(const map& x) {
                if (this != & x){
                    _tree = x._tree;
                    _alloc = x._alloc;
                    _comp = x._comp;
                }
                return *this;
            }

            ~map(){}

            /******************************************** (Iterators)******************************************/

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

            /******************************************** (Capacity)******************************************/

            bool empty() const {
                return _tree.size() == 0;
            }

            size_type size() const{
                return _tree.size();
            }

            size_type max_size() const{
                return _tree.max_size();
            }

            /******************************************** (Element access)******************************************/

            mapped_type& operator[] (const key_type& k){
                value_type f(k, mapped_type());
                typename RBT::nodePtr node = _tree.find(f);
                if (!node){
                    _tree.insert(f);
                    node = _tree.find(f);
                }
                return node->value.second;
            }

            /******************************************** (Modifiers)******************************************/


            ft::pair<iterator,bool> insert (const value_type& val){
                typename RBT::nodePtr node = _tree.find(val);
                
                if (node == NULL){
                    _tree.insert(val);
                    node = _tree.find(val);
                    return ft::pair<iterator,bool>(iterator(node), true);
                }
                return ft::pair<iterator,bool>(iterator(node), false);
            }

            iterator insert (iterator position, const value_type& val){
                (void)position;
                typename RBT::nodePtr node = _tree.find(val);
                if (node == NULL){
                    _tree.insert(val);
                    node = _tree.find(val);
                }
                return iterator(node);
                
            }
            
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last){
                typename RBT::nodePtr node;
                for (; first != last; first++)
                {
                    _tree.insert(*first);
                    if (!node)
                        _tree.insert(*first);
                }
            }

            void erase (iterator position){
                _tree.deleteNode(*position);
            }

            size_type erase (const key_type& k){
                value_type f(k, mapped_type());
                typename RBT::nodePtr node = _tree.find(f);
                if (node == NULL){
                    return 0;
                }
                _tree.deleteNode(f);
                return 1;
            }

            void erase (iterator first, iterator last){
                for (; first != last; first++)
                {
                    _tree.deleteNode(*first);
                }
            }

            void swap (map& x){
                map tmp = x;
                x = *this;
                *this = tmp;
            }

            void clear(){
                _tree.freeTree();
            }

            /******************************************** (Observers)******************************************/

            key_compare key_comp() const{
                return _comp;
            }

            class value_compare : public std::binary_function<value_type, value_type, bool>
            {
                public:
                    bool operator()(const value_type& left, const value_type& right) const{
                        return comp(left.first, right.first);
                    }
                    value_compare(key_compare pred = key_compare()) : comp(pred){};
                protected:
                    key_compare comp;
            };

            value_compare value_comp() const{
                return value_compare(_comp);
            }
            
            /******************************************** (Operations)******************************************/
            
            iterator find (const key_type& k){
                value_type f(k, mapped_type());
                typename RBT::nodePtr node = _tree.find(f);
                return iterator(node);
            }

            const_iterator find (const key_type& k) const{
                value_type f(k, mapped_type());
                typename RBT::nodePtr node = _tree.find(f);
                return const_iterator(node);
            }

            size_type count (const key_type& k) const{
                value_type f(k, mapped_type());
                typename RBT::nodePtr node = _tree.find(f);
                if (node == NULL){
                    return 0;
                }
                return 1;
            }

            iterator lower_bound (const key_type& k){
                typename RBT::nodePtr tmp = _tree.getRoot();
                typename RBT::nodePtr node = NULL;

                while (tmp != _tree.getNull()) {
                    if (_comp(tmp->value.first, k))
                        tmp = tmp->right;
                    else
                    {
                        node = tmp;
                        tmp = tmp->left;
                    }
                }
                return iterator(node);
            }
            
            const_iterator lower_bound (const key_type& k) const{
                typename RBT::nodePtr tmp = _tree.getRoot();
                typename RBT::nodePtr node = NULL;

                while (tmp != _tree.getNull()) {
                    if (_comp(tmp->data.first, k))
                        tmp = tmp->right;
                    else
                    {
                        node = tmp;
                        tmp = tmp->left;
                    }
                }
                return const_iterator(node);
            }

            iterator upper_bound (const key_type& k){
                typename RBT::nodePtr tmp = _tree.getRoot();
                typename RBT::nodePtr node = NULL;

                while (tmp != _tree.getNull()) {
                    if (_comp(k, tmp->value.first)){
                        node = tmp;
                        tmp = tmp->left;
                    }
                    else
                        tmp = tmp->right;
                }
                return iterator(node);
            }

            const_iterator upper_bound (const key_type& k) const{
                typename RBT::nodePtr tmp = _tree.getRoot();
                typename RBT::nodePtr node = NULL;

                while (tmp != _tree.getNull()) {
                    if (_comp(k, tmp->data.first)){
                        tmp = tmp->left;
                        node = tmp;
                    }
                    else
                        tmp = tmp->right;
                }
                return const_iterator(node);
            }

            ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
                return ft::pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k));
            }
            ft::pair<iterator,iterator> equal_range (const key_type& k){
                return ft::pair<iterator,iterator>(lower_bound(k), upper_bound(k));
            }

            /******************************************** (Allocator)******************************************/

            allocator_type get_allocator() const{
                return allocator_type();
            }
        
        private:
            typedef RedBlackTree<value_type, value_compare, allocator_type> RBT;
            RBT _tree;
            allocator_type _alloc;
            key_compare _comp;
    };

    
};


#endif 