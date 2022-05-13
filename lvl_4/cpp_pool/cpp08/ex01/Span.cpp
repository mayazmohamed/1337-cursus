/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:09:15 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/12 16:42:11 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructors
Span::Span()
{
	this->N = 0;
	std::cout << "\e[0;33mDefault Constructor called of Span\e[0m" << std::endl;
}

Span::Span(const Span &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Span\e[0m" << std::endl;
}

Span::Span(unsigned int N)
{
	this->N = N;
	std::cout << "\e[0;33mFields Constructor called of Span\e[0m" << std::endl;
}


// Destructor
Span::~Span()
{
	std::cout << "\e[0;31mDestructor called of Span\e[0m" << std::endl;
}


// Operators
Span & Span::operator=(const Span &assign)
{
	if (this->span != assign.span){
		this->span = assign.span;
		this->N = assign.N;
	}
	
	return *this;
}

void Span::addNumber(int nb){
	if (this->N <= this->span.size())
		throw (std::length_error("Error: already N elements stored"));
	this->span.push_back(nb);
}

int	Span::longestSpan(void)
{
	if (this->span.size() < 2)
		throw (std::length_error("Error: at least two numbers are needed"));
	return (*std::max_element(this->span.begin(), this->span.end()) - *std::min_element(this->span.begin(), this->span.end()));
}

int Span::shortestSpan(void){
	Span	tmp(*this);
	int x;

	if (this->span.size() < 2)
		throw (std::length_error("Error: at least two numbers are needed"));
	sort(tmp.span.begin(), tmp.span.end());
	x = tmp.span[1] - tmp.span[0];
	for (size_t i = 1; i < this->span.size() - 1; i++)
	{
		if (tmp.span[i + 1] - tmp.span[i] < x)
			x = tmp.span[i + 1] - tmp.span[i];
	}
	return (x);
}

void Span::rangeofiterators(std::vector<int>::iterator f, std::vector<int>::iterator l){
	if ((l - f) + this->span.size() < this->N)
		throw (std::length_error("Error: already N elements stored"));
	std::copy(f, l, std::back_inserter(this->span));
}
