/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:35:19 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/28 16:09:46 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class phoneBook
{
private:
	contact PhoneBook[8];
public:
	phoneBook(){};
	void fillTab(int i);
	void search(int contactSize);
};

#endif