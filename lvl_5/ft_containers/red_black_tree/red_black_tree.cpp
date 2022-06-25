/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:05:44 by momayaz           #+#    #+#             */
/*   Updated: 2022/06/25 12:22:15 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

#include <iostream>
#include <string.h>

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
    };
}









#endif