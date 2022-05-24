#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
# include <string>

class Span
{
	public:
		// Constructors
		Span();
		Span(const Span &copy);
		Span(unsigned int N);
		
		// Destruc`tor
		~Span();
		

		void addNumber(int nb);
		int longestSpan(void);
		int shortestSpan(void);
		void rangeofiterators(std::vector<int>::iterator f, std::vector<int>::iterator l);

		// Operators
		Span & operator=(const Span &assign);
		
		// Getters / Setters
		
	private:
		std::vector<int> span;
		unsigned int N;
		
};

#endif