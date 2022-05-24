/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:28:36 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/10 12:59:58 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include<iostream>
#include <iomanip>

class contact{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		contact(){};
		std::string getfirst()const;
		std::string getlast()const;
		std::string getnick()const;
		std::string getphon()const;
		std::string getdark()const;
		void setfirst(std::string firstName);
		void setlast(std::string lastName);
		void setnick(std::string nickName);
		void setphone(std::string phone);
		void setdark(std::string dark);
		void fill(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
		void affichContacts();
		void find();
};

#endif