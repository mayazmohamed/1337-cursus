/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:05:44 by momayaz           #+#    #+#             */
/*   Updated: 2022/07/09 12:21:01 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

#include <iostream>
#include <string.h>
#include "../implement/pair.hpp"

namespace ft{
    
    template <class T>
    struct Node {
        T value;
        bool isBlack;
        bool isLeftChild;
        Node *parent;
        Node *left;
        Node *right;
        
        Node () {
            value = T();
            isBlack = false;
            parent = nullptr;
            left = nullptr;
            right = nullptr;
            isLeftChild = false;
        } 
        Node(T val) {
            value = val;
            isBlack = false;
            parent = nullptr;
            left = nullptr;
            right = nullptr;
            isLeftChild = false;
        }
    };

     template <class Key, class Value, class Alloc = std::allocator< Node< ft::pair< Key, Value > > > >
    class RedBlackTree
    {
        typedef std::size_t size_type;
        typedef Key key_type;
        typedef Value mapped_type;
        typedef Alloc allocator_type;
        typedef ft::pair< key_type, mapped_type> value_type;
        typedef Node<value_type> Node;
        typedef Node* nodePtr;
        typedef Node& nodeRef;
        
        private :
            nodePtr _root;
            nodePtr _nil;
            size_type _size;
            allocator_type _alloc;
            
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
            void deleteN(nodePtr root, int k){
                nodePtr node = _nil;
                nodePtr x, y;
                while (root != _nil){
                    if (root->value.first == k)
                        node = root;
                    if (root->value.first <= k)
                        root = root->right;
                    else
                        root = root->left;
                }
                if (node == _nil){
                    std::cout << "Key not found" << std::endl;
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
                _alloc.deallocate(node, 1);
                if (y_original_color == true)
                    deleteFixup(x);
                _size--;
            }
            
        public:
           RedBlackTree(){
                _size = 0;
                _nil = _alloc.allocate(1);
                _nil->isBlack = true;
                _nil->left = nullptr;
                _nil->right = nullptr;
                _root = _nil;
                }
            ~RedBlackTree(){
            }
            RedBlackTree(const RedBlackTree &copy){
             _root = copy._root;
             _size = copy._size;
            }
            RedBlackTree & operator=(const RedBlackTree &assign){
             if (this != &assign){
                  _root = assign._root;
                  _size = assign._size;
             }
             return *this;
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
                std::cout << "[ " << root->value.first << " , " << root->value.second << " ]" << " (" << (root->isBlack ? "BLACK" : "RED") << ")" << "\n";
                printTree(count ,root->left, space);
            }
            void insert(Key k, Value val){
                nodePtr node = _alloc.allocate(1);
                node->parent = nullptr;
                node->value.first = k;
                node->value.second = val;
                node->isBlack = false;
                node->left = _nil;
                node->right = _nil;
                nodePtr y = nullptr;
                nodePtr x = _root;
                while (x != _nil){
                    y = x;
                    if (node->value.first < x->value.first)
                        x = x->left;
                    else
                        x = x->right;
                }
                node->parent = y;
                if (y == nullptr)
                    _root = node;
                else if (node->value.first < y->value.first)
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
            nodePtr minimum(nodePtr node){
                while (node->left != _nil)
                    node = node->left;
                return node;
            }
            void deleteNode(int k){
                deleteN(_root,  k);
            }
    };

}


#endif