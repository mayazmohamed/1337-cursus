/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:11:16 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/12 14:18:20 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
template <typename T>

typename T::iterator easyfind(T c, int a){
    typename T::iterator res = find(c.begin(), c.end(), a);
    if (res != c.end())
        return res;
    throw std::logic_error("no occurrence is found");
}





#endif