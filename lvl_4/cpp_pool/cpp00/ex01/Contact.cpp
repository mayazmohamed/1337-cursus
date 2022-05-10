/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 00:27:38 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/04 15:15:53 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void contact:: fill(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret){
			this->firstName = firstName;
			this->lastName = lastName;
			this->nickName = nickName;
			this->phoneNumber = phoneNumber;
			this->darkestSecret = darkestSecret;
		};
void contact:: affichContacts(){
			std::cout << "firstName >>";
			std::cout << this->firstName << std::endl;
			std::cout << "lastName >>";
			std::cout << this->lastName << std::endl;
			std::cout << "nickName >>";
			std::cout << this->nickName << std::endl;
			std::cout << "phoneNumber >>";
			std::cout << this->phoneNumber << std::endl;
			std::cout << "darkestSecret >>";
			std::cout << this->darkestSecret << std::endl;
		};
void contact:: find(){
			if(firstName.length() > 10){
				std::cout << firstName.substr(0, 9);
				std::cout << ".";
			}
			else{
				std::cout << std::setw(10);
				std::cout << firstName;
			}
			std::cout << "|";
			if(lastName.length() > 10){
				std::cout << lastName.substr(0, 9);
				std::cout << ".";
			}
			else{
				std::cout << std::setw(10);
				std::cout << lastName;
			}
			std::cout << "|";
			if(nickName.length() > 10){
				std::cout << nickName.substr(0, 9);
				std::cout << ".";
			}
			else{
				std::cout << std::setw(10);
				std::cout << nickName;
			}
			std::cout << std::endl;
		};