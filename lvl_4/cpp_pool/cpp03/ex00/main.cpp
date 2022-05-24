/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:17:42 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/16 13:15:11 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <iomanip>

int main(){
	std::string op;
	std::string name;
	std::string search;
	std::string target;
	ClapTrap players[5];
	unsigned int amount;
	int j = 0;
	int i = 0;
	int HP;
	int AD;
	int EP;

	std::cout << "*******************************************" << std::endl;
	std::cout << "* set: set the players value manual       *" << std::endl;
	std::cout << "* defult: set the players value by defult *" << std::endl;
	std::cout << "* EXIT                                    *" << std::endl;
	std::cout << "*******************************************" << std::endl;
	while (std::cin.good())
	{
		std::cout << "youre option please: >> ";
		std::cin >> op;
		std::cout << std::endl;
		if (!(op.compare("set"))){
			while (i < 5){
				std::cout << "set player N" << i + 1 << std::endl;
				std::cout << "Name >> ";
				std::cin >> name;
				std::cout << std::endl;
				std::cout << "Hit points >> ";
				std::cin >> HP;
				std::cout << std::endl;
				std::cout << "Energy points >> ";
				std::cin >> EP;
				std::cout << std::endl;
				std::cout << "Attack damage >> ";
				std::cin >> AD;
				players[i].setname(name);
				players[i].setHP(HP);
				players[i].setEP(EP);
				players[i].setAD(AD);
				i++;
			}
			break;
		}
		else if(!(op.compare("defult"))){
			while (i < 5){
				players[i] = ClapTrap();
				std::cout << "set player N" << i + 1 << std::endl;
				std::cout << "Name >> ";
				std::cin >> name;
				players[i].setname(name);
				i++;
			}
			break;
		}
		else if(!(op.compare("EXIT"))){
			std::cout << "Bye!" ;
			exit(1);
		}
		else{
			std::cout << "invalid option pleas try again !" << std::endl;
		}
	}
	std::cout << std::setw(10);
	std::cout << "Name" ;
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "HP";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "EP";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "AD" << std::endl;
	i = 0;
	while (i < 5){
		std::cout << std::setw(10);
		std::cout << players[i].getname() ;
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << players[i].getHP();
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << players[i].getEP();
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << players[i].getAD() << std::endl;
		i++;
	}
	while (std::cin.good()){
		std::cout << "select player by Name > " ;
		std::cin >> search;
		std:: cout << std::endl;
		if(!(search.compare("EXIT"))){
			std::cout << "Bye!" ;
			exit(1);
		}
		i = 0;
		while (i < 5){
			if (!(players[i].getname().compare(search))){
				break;
			}
			i++;
		}
		if (i == 5){
			std::cout << "player does not exist" ;
			std:: cout << std::endl;
			continue ;
		}
		j = 0;
		std::cout << "*********************" << std::endl;
		std::cout << "* attack            *" << std::endl;
		std::cout << "* berepaired        *" << std::endl;
		std::cout << "* EXIT              *" << std::endl;
		std::cout << "*********************" << std::endl;
		std::cout << "youre option please: >> ";
		std::cin >> op;
		std::cout << std::endl;
		if (!(op.compare("attack"))){
			std::cout << "select your target > " ;
			std::cin >> target;
			std:: cout << std::endl;
			if (!(search.compare(target))){
				std::cout << "Really !!!" << std::endl;
				continue;
		}
		while (j < 5){
			if (!(players[j].getname().compare(target))){
				break;
			}
			j++;
		}
		if (j == 5){
			std::cout << "target does not exist" ;
			continue;
		}
			if (players[i].getEP() > 0 && players[i].getHP() > 0){
				players[i].attack(target);
				players[j].takeDamage((unsigned int)(players[i].getAD()));
			}
			else
				std::cout << "you are dead or your energy is 0 " << std::endl;

		}
		else if(!(op.compare("berepaired"))){
			if (players[i].getEP() > 0 && players[i].getHP() > 0){
				std::cout << "Enter the amount > " ;
				std::cin >> amount;
				std:: cout << std::endl;
				players[i].beRepaired(amount);
			}
			else
				std::cout << "you are dead or your energy is 0 " << std::endl;
		}
		else if(!(op.compare("EXIT"))){
			std::cout << "Bye!" ;
			exit(1);
		}
		else{
			std::cout << "invalid option pleas try again !" << std::endl;
		}
		std::cout << std::setw(10);
		std::cout << "Name" ;
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << "HP";
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << "EP";
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << "AD" << std::endl;
		i = 0;
		while (i < 5){
			std::cout << std::setw(10);
			std::cout << players[i].getname() ;
			std::cout << "|";
			std::cout << std::setw(10);
			std::cout << players[i].getHP();
			std::cout << "|";
			std::cout << std::setw(10);
			std::cout << players[i].getEP();
			std::cout << "|";
			std::cout << std::setw(10);
			std::cout << players[i].getAD() << std::endl;
			i++;
		}
	}
}