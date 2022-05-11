/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:56:21 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/11 16:14:48 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <stdint.h>


 typedef struct s_Serialization
 {
     int a ;
 } t_Serialization;
 
 uintptr_t serialize(t_Serialization* ptr);
 t_Serialization* deserialize(uintptr_t raw);

#endif