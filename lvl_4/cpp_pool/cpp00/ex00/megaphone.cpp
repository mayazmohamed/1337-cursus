/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:38:52 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/27 17:08:20 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

int main(int ac, char *av[])
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return (0);
	}
	for (size_t i = 1; av[i] != '\0'; i++)
		for (size_t j = 0; av[i][j] != '\0'; j++)
			std::cout << (char)toupper(av[i][j]);
	std::cout << std::endl;
	return (0);
}