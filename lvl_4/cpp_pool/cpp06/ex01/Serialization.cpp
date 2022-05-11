/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:56:19 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/11 16:09:23 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

uintptr_t serialize(t_Serialization* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

t_Serialization* deserialize(uintptr_t raw){
    return reinterpret_cast<t_Serialization *>(raw);
}