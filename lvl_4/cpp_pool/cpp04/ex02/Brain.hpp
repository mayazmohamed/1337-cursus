/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:45:02 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/06 14:34:25 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>


class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(Brain &F);
	Brain & operator=(const Brain &F);
	std::string getidea(int id)const;
	void setidea(std::string idea, int id);
	~Brain();
};

#endif