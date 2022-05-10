/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyAwesomePhoneBook.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:31:59 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/28 17:03:04 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	std::string op;
	int index = 0;
	int contactSize = 0;
	contact conta;
	phoneBook phoneb;

	while(1){
		std::cout << "**************************************" << std::endl;
		std::cout << "* ADD: save a new contact            *" << std::endl;
		std::cout << "* SEARCH: display a specific contact *" << std::endl;
		std::cout << "* EXIT: quit the program             *" << std::endl;
		std::cout << "**************************************" << std::endl;
		std::cout << "youre option please: >> ";
		std::cin >> op;
		std::cout << std::endl;
		if (!(op.compare("ADD"))){
			phoneb.fillTab(index);
			index++;
			if (contactSize < 8)
				contactSize++;
		}
		if (!(op.compare("SEARCH"))){
			std::cout << "     index| firstName|  lastName|  nickName" << std::endl;
			if (contactSize == 0)
				continue;
			phoneb.search(contactSize);
		}
		if (!(op.compare("EXIT")))
			break;
		if (index == 8)
			index = 0;
	}
	std::cout << "See you next time " << std::endl;
	return (0);
}