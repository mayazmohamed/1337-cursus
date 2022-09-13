/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:05:44 by momayaz           #+#    #+#             */
/*   Updated: 2022/08/09 10:39:39 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

#include <iostream>
#include <string.h>
#include "../implement/pair.hpp"
#include "../implement/iterator.hpp"


namespace ft{
    
    template<class Iterator>
    class iteratorRBTreverse;
    
    template<class T>
    class iteratorRBT;
    

    
    template <class T>
    struct Node {
        T value;
        bool isBlack;
        bool isLeftChild;
        Node<T> *parent;
        Node<T> *left;
        Node<T> *right;
        
        Node () : value(T()), isBlack(true), isLeftChild(false), parent(nullptr), left(nullptr), right(nullptr) {}
        Node(T val) : value(val), isBlack(true), isLeftChild(false), parent(nullptr), left(nullptr), right(nullptr) {}
    };

     template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
    class RedBlackTree
    {
    public:
        typedef std::size_t size_type;
        typedef T value_type;
        typedef Node<value_type> node_type;
        typedef node_type* nodePtr;
        typedef node_type& node_reference;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef std::allocator<node_type> node_allocator_type;
        typedef iteratorRBT<value_type> iterator;
        typedef iteratorRBT<value_type> const_iterator;
        typedef iteratorRBTreverse<iterator> reverse_iterator;
        typedef iteratorRBTreverse<const_iterator> const_reverse_iterator;
        
        private :
            nodePtr _root;
            nodePtr _nil;
            size_type _size;
            allocator_type _alloc;
            node_allocator_type _node_alloc;
            Compare _comp;
            
            
            void leftRotate(nodePtr node){
                nodePtr right = node->right;
                node->right = right->left;
                if(right->left != _nil)
                    right->left->parent = node;
                right->parent = node->parent;
                if(node->parent == nullptr)
                    _root = right;
                else if(node == node->parent->left)
                    node->parent->left = right;
                else
                    node->parent->right = right;
                right->left = node;
                node->parent = right;
            }

            void rightRotate(nodePtr node){
                nodePtr left = node->left;
                node->left = left->right;
                if(left->right != _nil)
                    left->right->parent = node;
                left->parent = node->parent;
                if(node->parent == nullptr)
                    _root = left;
                else if(node == node->parent->right)
                    node->parent->right = left;
                else
                    node->parent->left = left;
                left->right = node;
                node->parent = left;
            }
            
            void insertFixup(nodePtr node){
                // if aunt is red color flip
                //if aunt is black rotate
                nodePtr aunt;
                while (!node->parent->isBlack){
                    if (node->parent == node->parent->parent->right){
                        aunt = node->parent->parent->left;
                        if (!aunt->isBlack){
                            aunt->isBlack = true;
                            node->parent->isBlack = true;
                            node->parent->parent->isBlack = false;
                            node = node->parent->parent;
                        }else {
                            if (node == node->parent->left){
                                node = node->parent;
                                rightRotate(node);
                            }
                            node->parent->isBlack = true;
                            node->parent->parent->isBlack = false;
                            leftRotate(node->parent->parent);
                        }
                    }else {
                        aunt = node->parent->parent->right;
                        if (!aunt->isBlack){
                            aunt->isBlack = true;
                            node->parent->isBlack = true;
                            node->parent->parent->isBlack = false;
                            node = node->parent->parent;
                        }else {
                            if (node == node->parent->right){
                                node = node->parent;
                                leftRotate(node);
                            }
                            node->parent->isBlack = true;
                            node->parent->parent->isBlack = false;
                            rightRotate(node->parent->parent);
                        }
                    }
                    if (node == _root)
                        break;
                }
                _root->isBlack = true;
            }

            void deleteFixup(nodePtr node){
                nodePtr sib;
                while (node != _root && node->isBlack == true){
                    if (node == node->parent->left){
                        sib = node->parent->right;
                        if(sib->isBlack == false){
                            sib->isBlack = true;
                            node->parent->isBlack = false;
                            leftRotate(node->parent);
                            sib = node->parent->right;
                        }
                    if (sib->left->isBlack == true && sib->right->isBlack == true){
                        sib->isBlack = false;
                        node = node->parent;
                    }else {
                        if (sib->right->isBlack == true){
                            sib->left->isBlack = true;
                            sib->isBlack = false;
                            rightRotate(sib);
                            sib = node->parent->right;
                        }
                        sib->isBlack = node->parent->isBlack;
                        node->parent->isBlack = true;
                        sib->right->isBlack = true;
                        leftRotate(node->parent);
                        node = _root;
                    }
                }else {
                    sib = node->parent->left;
                    if (sib->isBlack == false){
                        sib->isBlack = true;
                        node->parent->isBlack = false;
                        rightRotate(node->parent);
                        sib = node->parent->left;
                    }
                    if (sib->right->isBlack == true && sib->left->isBlack == true){
                        sib->isBlack = false;
                        node = node->parent;
                    }else {
                        if (sib->left->isBlack == true){
                            sib->right->isBlack = true;
                            sib->isBlack = false;
                            leftRotate(sib);
                            sib = node->parent->left;
                        }
                        sib->isBlack = node->parent->isBlack;
                        node->parent->isBlack = true;
                        sib->left->isBlack = true;
                        rightRotate(node->parent);
                        node = _root;
                    }
                }
            }
                node->isBlack = true;
        }
            
            void deleteN(nodePtr root, value_type k){
                nodePtr node = _nil;
                nodePtr x, y;
                while (root != _nil){
                    if (!_comp(root->value, k) && !_comp(k, root->value))
                        node = root;
                    if (_comp(root->value, k))
                        root = root->right;
                    else
                        root = root->left;
                }
                if (node == _nil){
                    return;
                }
                y = node;
                int y_original_color = y->isBlack;
                if (node->left == _nil){
                    x = node->right;
                    transplant(node, node->right);
                }else if (node->right == _nil){
                    x = node->left;
                    transplant(node, node->left);
                }else {
                    y = minimum(node->right);
                    y_original_color = y->isBlack;
                    x = y->right;
                    if (y->parent == node)
                        x->parent = y;
                    else {
                        transplant(y, y->right);
                        y->right = node->right;
                        y->right->parent = y;
                    }
                    transplant(node, y);
                    y->left = node->left;
                    y->left->parent = y;
                    y->isBlack = node->isBlack;
                }
                clearNode(node);
                if (y_original_color == true)
                    deleteFixup(x);
                _nil->parent = nullptr;
                _size--;
            }
            
            static nodePtr minimum(nodePtr node){
                 if (!node || !node->left)
                    return nullptr;

                while (node->left->parent)
                    node = node->left;
                return node;
            }

            static nodePtr maximum(nodePtr node){
                 if (!node || !node->right)
                    return nullptr;

                while (node->right && node->right->parent)
                    node = node->right;
                return node;
            }
            
            
        public:
           explicit RedBlackTree(
                const key_compare &comp = key_compare(),
                const allocator_type &alloc = allocator_type()) : _alloc(alloc), _comp(comp){
                _size = 0;
                _nil = _node_alloc.allocate(1);
                _node_alloc.construct(_nil, Node<value_type>(value_type()));
                _nil->isBlack = true;
                _nil->left = nullptr;
                _nil->right = nullptr;
                _root = _nil;
                }
           
            ~RedBlackTree(){
            }
            
            RedBlackTree(const RedBlackTree &copy) : _nil(nullptr), _root(nullptr){
             *this = copy;
            }
            
            RedBlackTree & operator=(const RedBlackTree &assign){
             if (this != &assign){
                    _alloc = assign._alloc;
                    _comp = assign._comp;
                    _node_alloc = assign._node_alloc;
                    _root = copyRBT(assign._root, assign._nil);
                    _size = assign._size;
             }
             return *this;
            }
            
            static nodePtr successor(nodePtr node){
                if (node->right && node->right->parent)
                    return minimum(node->right);
                nodePtr y = node->parent;
                while (y && node == y->right){
                    node = y;
                    y = y->parent;
                }
                return y;
            }

            static nodePtr predecessor(nodePtr node){
                if (node->left && node->left->parent)
                    return maximum(node->left);
                nodePtr y = node->parent;
                while (y && node == y->left){
                    node = y;
                    y = y->parent;
                }
                return y;
            }
            
            nodePtr copyRBT(nodePtr node, nodePtr null) {
                if (node == null)
                    return _nil;
                    
                nodePtr new_node = _node_alloc.allocate(1);
                _node_alloc.construct(new_node, node_type(node->value));
                new_node->isBlack = node->isBlack;
                new_node->left = copyRBT(node->left, null);
                new_node->right = copyRBT(node->right, null);
                new_node->parent = nullptr;
                if (new_node->left != _nil)
                    new_node->left->parent = new_node;
                if (new_node->right != _nil)
                    new_node->right->parent = new_node;
                return new_node;
            }

            nodePtr getRoot() const {
                return _root;
            }

            nodePtr getNull() const {
                return _nil;
            }
            
            void printTree(int count, nodePtr root = nullptr, int space = 0){
                if (root == _nil)
                    return;
                if (_root == nullptr)
                    return;
                if (root == nullptr) {
                    if (space == 0)
                        root = _root;
                    else
                        return;
                }
                space += count;
                printTree(count ,root->right, space);
                for (int i = count; i < space; i++)
                    std::cout << "\t";
                std::cout << "[ " << root->value << " , " << root->value << " ]" << " (" << (root->isBlack ? "BLACK" : "RED") << ")" << "\n";
                printTree(count ,root->left, space);
            }
            
            void insert(value_type value){
                nodePtr node = _node_alloc.allocate(1);
                node->parent = nullptr;
                _node_alloc.construct(node, node_type(value));
                node->isBlack = false;
                node->left = _nil;
                node->right = _nil;
                nodePtr y = nullptr;
                nodePtr x = _root;
                while (x != _nil){
                    y = x;
                    if (_comp(node->value, x->value))
                        x = x->left;
                    else
                        x = x->right;
                }
                node->parent = y;
                if (y == nullptr)
                    _root = node;
                else if (_comp(node->value , y->value))
                    y->left = node;
                else
                    y->right = node;
                if (node->parent == nullptr) {
                    node->isBlack = true;
                    _size++;
                    return;
                }
                if (node->parent->parent == nullptr){
                    _size++;
                    return;
                }
                insertFixup(node);
                _size++;
            }
            
            void transplant(nodePtr u, nodePtr v){
                if (u->parent == nullptr)
                    _root = v;
                else if (u == u->parent->left)
                    u->parent->left = v;
                else
                    u->parent->right = v;
                v->parent = u->parent;
            }
            
            void deleteNode(value_type value){
                deleteN(_root, value);
            }

            nodePtr begin() const
            {
                return minimum(_root);
            }

            nodePtr end() const
            {
                return maximum(_root);
            }
            size_type size() const {
                return _size;
            }

            size_type max_size() const {
                return _node_alloc.max_size();
            }

            void clearNode(nodePtr node){
                if (node == _nil)
                    return;
                _node_alloc.destroy(node);
                _node_alloc.deallocate(node, 1);
            }

            void clearRBT(nodePtr node){
                if (node  == _nil)
                    return;
                clearRBT(node->left);
                clearRBT(node->right);
                _node_alloc.destroy(node);
                _node_alloc.deallocate(node, 1);
            }
            void freeTree(){
                clearRBT(_root);
                _root = _nil;
                _size = 0;
            }

            nodePtr find(const value_type &key) const
            {
                nodePtr current = _root;
                nodePtr tmp = nullptr;

                while (current != _nil)
                {
                    if (!(_comp(current->value, key) || _comp(key, current->value)))
                        tmp = current;
                    if (_comp(current->value, key))
                        current = current->right;
                    else
                        current = current->left;
                }
                return (tmp);
            }
    };

    template<class T>
    class iteratorRBT{
        public:
            typedef std::size_t size_type;
            typedef T value_type;
            typedef value_type& reference;
            typedef value_type* pointer;
            typedef std::ptrdiff_t difference_type;
            typedef std::bidirectional_iterator_tag iterator_category;
            typedef Node<value_type>* nodePtr;

            iteratorRBT(nodePtr node): _node(node){}
            
            iteratorRBT(const iteratorRBT &copy){
                *this = copy;
            }

            iteratorRBT(){}
            
            ~iteratorRBT(){}
            
            iteratorRBT & operator=(const iteratorRBT &assign){
                if (this != &assign){
                    _node = assign._node;
                }
                return *this;
            }

            reference operator*() const{
                return _node->value;
            }

            pointer operator->() const{
                return &_node->value;
            }

            iteratorRBT & operator++(){
                _node = RedBlackTree<T>::successor(_node);
                return *this;
            }

            iteratorRBT operator++(int){
                iteratorRBT temp(*this);
                ++*this;
                return temp;
            }

            iteratorRBT & operator--(){
                _node = RedBlackTree<T>::predecessor(_node);
                return *this;
            }

            iteratorRBT operator--(int){
                iteratorRBT temp(*this);
                --*this;
                return temp;
            }

            bool operator==(const iteratorRBT &rhs)const{
                return _node == rhs._node;
            }

            bool operator!=(const iteratorRBT &rhs)const{
                return _node != rhs._node;
            }

            nodePtr getNode(){
                return _node;
            }

            nodePtr base(){
                return _node;
            }

        private:
            nodePtr _node;
            
    };

    template<class Iterator>
    class iteratorRBTreverse{
        public:
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<Iterator>::value_type value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer pointer;
            typedef typename iterator_traits<Iterator>::reference reference;
        
        iteratorRBTreverse(){}
        
        ~iteratorRBTreverse(){}
        
        iteratorRBTreverse(Iterator it): _base(it){
        }

        template <class Iter>
        iteratorRBTreverse(const iteratorRBTreverse<Iter> &rev_it) : _base(rev_it._base) {}

        iteratorRBTreverse(const iteratorRBTreverse &copy): _base(copy._base){}

        iteratorRBTreverse & operator=(const iteratorRBTreverse &assign){
            if (this != &assign){
                _base = assign._base;
            }
            return *this;
        }
        
        iterator_type base() const{
            return _base;
        }
        
        iteratorRBTreverse & operator++(){
            --_base;
            return *this;
        }

        iteratorRBTreverse operator++(int){
            iteratorRBTreverse temp = *this;
            --_base;
            return temp;
        }

        iteratorRBTreverse & operator--(){
            ++_base;
            return *this;
        }

        iteratorRBTreverse operator--(int){
            iteratorRBTreverse temp = *this;
            ++_base;
            return temp;
        }

        bool operator==(const iteratorRBTreverse &rhs) const{
            return _base == rhs._base;
        }

        bool operator!=(const iteratorRBTreverse &rhs) const{
            return _base != rhs._base;
        }

        reference operator*() const{
            return *_base;
        }

        pointer operator->() const{
            return &*_base;
        }
        
        private:
            iterator_type _base;
    };  
    
}

#endif