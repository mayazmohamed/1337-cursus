/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:40:26 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/11 15:41:10 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_HPP
# define CAST_HPP

# include <iostream>
# include <string>
#include <limits>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define NOTYP -1

class Cast
{
	public:
		// Constructors
		Cast();
		Cast(const Cast &copy);
		Cast(int type, int intType, float floatType, double doubleType, char charType);
		
		// Destructor
		~Cast();
		
		// Operators
		Cast & operator=(const Cast &assign);
		
		// Getters / Setters
		int getType() const;
		int getIntType() const;
		float getFloatType() const;
		double getDoubleType() const;
		char getCharType() const;

		//Check type
		void getDataType(char* str);
		void fillClass(char* str);
		void printResult(char *str);

		//conversion
		void CharToOther();
		void IntToOther();
		void FloaToOther();
		void DoubleToOther();
		
		// Exceptions
		class NOTYPE : public std::exception {
			virtual const char* what() const throw();
		};
		class NOVALUE : public std::exception {
			virtual const char* what() const throw();
		};
		
	private:
		int _type;
		int _intType;
		float _floatType;
		double _doubleType;
		char _charType;
		
};


// get data type
int checkIfInt(char* str);
int checkIfFD(char* str);


#endif