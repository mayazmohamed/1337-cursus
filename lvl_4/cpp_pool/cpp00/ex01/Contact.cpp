/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 00:27:38 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/10 13:05:09 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string contact:: getfirst()const{
	return this->firstName;
}

std::string contact:: getlast()const{
	return this->lastName;
}

std::string contact:: getnick()const{
	return this->nickName;
}

std::string contact:: getphon()const{
	return this->phoneNumber;
}

std::string contact:: getdark()const{
	return this->darkestSecret;
}

void contact:: setfirst(std::string firstName){
	this->firstName = firstName;
}

void contact:: setlast(std::string lastName){
	this->lastName = lastName;
}


void contact:: setnick(std::string nickName){
	this->nickName = nickName;
}


void contact:: setphone(std::string phone){
	this->phoneNumber = phone;
}

void contact:: setdark(std::string dark){
	this->darkestSecret = dark;
}


void contact:: fill(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret){
			this->setfirst(firstName);
			this->setlast(lastName);
			this->setnick(nickName);
			this->setphone(phoneNumber);
			this->setdark(darkestSecret);
		};
void contact:: affichContacts(){
			std::cout << "firstName >>";
			std::cout << this->getfirst() << std::endl;
			std::cout << "lastName >>";
			std::cout << this->getlast() << std::endl;
			std::cout << "nickName >>";
			std::cout << this->getnick() << std::endl;
			std::cout << "phoneNumber >>";
			std::cout << this->getphon() << std::endl;
			std::cout << "darkestSecret >>";
			std::cout << this->getdark() << std::endl;
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