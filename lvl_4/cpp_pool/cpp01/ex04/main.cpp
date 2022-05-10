/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 00:14:59 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/30 16:51:25 by momayaz          ###   ########.fr       */
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
	if (!strcmp(av[1], "") || !strcmp(av[2], "")  || !strcmp(av[3], "") ){
		std::cout << "invalid input" << std::endl;
		return (0);
	}
	read.open(av[1]);
	if (!read){
		std::cout << "fill not found or permission denied " << std::endl;
		return (0);
	}
	int found;
	std::string filename("tmp.txt");
	std::ofstream out;
	out.open(filename, std::ios_base::app);
	while (getline(read, line)){
		while ((found = line.find(av[2])) != -1){
			line.erase(found, strlen(av[3]));
			line.insert(found, av[3]);
		}
		out << line << std::endl;
	}
	out.close();
	read.close();
	return(0);
}