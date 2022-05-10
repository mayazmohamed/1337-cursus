/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:35:14 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/28 17:12:48 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>

void phoneBook::fillTab(int i){
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
		std::cout << "firstName: >>";
		std::cin >> firstName;
		std::cout << "lastName: >>";
		std::cin >> lastName;
		std::cout << "nickName: >>";
		std::cin >> nickName;
		std::cout << "phoneNumber: >>";
		std::cin >> phoneNumber;
		std::cout << "darkestSecret: >>";
		std::cin >> darkestSecret;
		PhoneBook[i].fill(firstName, lastName, nickName, phoneNumber, darkestSecret);
	};
void phoneBook:: search(int contactSize){
		int index;
		for (int i = 0; i < contactSize; i++)
		{
			std::cout << std::setw(10);
			std::cout << i + 1;
			std::cout << "|";
			PhoneBook[i].find();
		}
		std::cout << "index: >>";
		std::cin >> index;
		if (index > contactSize || index < 1){
			std::cout << "wrong index try again" << std::endl;
			return;
		}
		PhoneBook[index - 1].affichContacts();
	};