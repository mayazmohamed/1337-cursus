/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 00:14:59 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/14 16:13:10 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>


int main(int ac, char *av[]){
	std::ifstream read;
	std::string line;

	if (ac != 4){
		std::cout << "wrong args number" << std::endl;
		return (0);
	}
	if (!strcmp(av[1], "") || !strcmp(av[2], "")){
		std::cout << "invalid input" << std::endl;
		return (0);
	}
	read.open(av[1]);
	if (!read){
		std::cout << "fill not found or permission denied " << std::endl;
		return (0);
	}
	std::string filename("tmp.txt");
	std::ofstream out;
	out.open(filename);
	int found = 0;
	while (getline(read, line)){
		while ((found = line.find(std::string(av[2]), found)) != -1){
			line.erase(found, strlen(av[3]));
			line.insert(found, std::string (av[3]));
		}
		out << line << std::endl;
	}
	out.close();
	read.close();
	return(0);
}