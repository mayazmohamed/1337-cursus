/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:40:30 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/11 15:41:00 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cast.hpp"

// Constructors
Cast::Cast()
{
	_type = -1;
	_intType = 0;
	_floatType = 0.0f;
	_doubleType = 0.0;
	_charType = 0;
	std::cout << "\e[0;33mDefault Constructor called of Cast\e[0m" << std::endl;
}

Cast::Cast(const Cast &copy)
{
	_type = copy.getType();
	_intType = copy.getIntType();
	_floatType = copy.getFloatType();
	_doubleType = copy.getDoubleType();
	_charType = copy.getCharType();
	std::cout << "\e[0;33mCopy Constructor called of Cast\e[0m" << std::endl;
}

Cast::Cast(int type, int intType, float floatType, double doubleType, char charType)
{
	_type = type;
	_intType = intType;
	_floatType = floatType;
	_doubleType = doubleType;
	_charType = charType;
	std::cout << "\e[0;33mFields Constructor called of Cast\e[0m" << std::endl;
}


// Destructor
Cast::~Cast()
{
	std::cout << "\e[0;31mDestructor called of Cast\e[0m" << std::endl;
}


// Operators
Cast & Cast::operator=(const Cast &assign)
{
	_type = assign.getType();
	_intType = assign.getIntType();
	_floatType = assign.getFloatType();
	_doubleType = assign.getDoubleType();
	_charType = assign.getCharType();
	return *this;
}


// Getters / Setters
int Cast::getType() const
{
	return _type;
}
int Cast::getIntType() const
{
	return _intType;
}
float Cast::getFloatType() const
{
	return _floatType;
}
double Cast::getDoubleType() const
{
	return _doubleType;
}
char Cast::getCharType() const
{
	return _charType;
}


// Exceptions
const char * Cast::NOTYPE::what() const throw()
{
	return "no type find";
}
const char * Cast::NOVALUE::what() const throw()
{
	return "pleas set a value";
}


// detect the type of the parameter
void Cast::getDataType(char* str){
	if (str == nullptr || !strcmp(str, ""))
		throw Cast::NOVALUE();
	this->_type = -1;
	this->_type = checkIfInt(str);
	if (this->_type == INT)
		return;
	this->_type = checkIfFD(str);
	if (this->_type == FLOAT)
		return;
	if (this->_type == DOUBLE)
		return;
	if (strlen(str) == 1)
		this->_type = CHAR;
	if (this->_type == NOTYP)
		throw Cast::NOTYPE();
		
}

int checkIfInt(char* str){
	int i = 0;
	if (str[i] == '-')
		i++;
	while (str[i]){
		if (!isdigit(str[i]))
			return NOTYP;
		i++;
	}
	return INT;
}

int checkIfFD(char* str){
	int index = 0;
	int cp = 0;
	std::string F[4] = {"-inff",
				"+inff",
				"nanf",
				"inff"};
				
	std::string D[4] = {"-inf",
				"+inf",
				"nan",
				"inf"};
				
	for (int i = 0; i < 4; i++)
		if (str == F[i])
			return FLOAT;
	for (int i = 0; i < 4; i++)
		if (!D[i].compare(str)){
			return DOUBLE;
		}
	if (str[index] == '-')
		index++;
	while (str[index]){
		if (!isdigit(str[index]))
			break;
		index++;
	}
	if (str[index++] != '.')
		return NOTYP;
	while (str[index]){
		if (!isdigit(str[index]))
			break;
		index++;
		cp++;
	}
	if ((str[index] != 0 && str[index] != 'f') || cp == 0 )
		return NOTYP ;
	if (str[index] == 'f' && str[index + 1])
		return NOTYP;
	if (str[index] == 'f')
		return FLOAT;
	return DOUBLE;
}

void Cast::fillClass(char* str){
	this->getDataType(str);	
	if (this->_type == INT){
		this->_intType = std::stoi(str);
		this->IntToOther();
		return;
	}
	if (this->_type == FLOAT){
		this->_floatType = std::stof(str);
		this->FloaToOther();
		return;
	}
	if (this->_type == DOUBLE){
		this->_doubleType = std::stod(str);
		this->DoubleToOther();
		return;
	}
	if (this->_type == CHAR){
		this->_charType = str[0];
		this->CharToOther();
		return;
	}
}


void Cast::printResult(char *str){
	this->fillClass(str);
	
	if (this->_doubleType < CHAR_MIN || this->_doubleType > CHAR_MAX || this->_doubleType != this->_doubleType)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(this->_charType))
		std::cout <<  "non printable" << std::endl;
	else
		std::cout << "char Value : " << this->_charType << std::endl;
		
	if (this->_doubleType < INT_MIN || this->_doubleType > INT_MAX || this->_doubleType != this->_doubleType)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "int Value : " << this->_intType << std::endl;
		
	if (this->_type == 1 || this->_type == 2 || this->_floatType == (int)this->_floatType)
		std::cout << "float Value : "  << this->_floatType << ".0f" << std::endl;
	else 
		std::cout << "float Value : "  << this->_floatType << "f" << std::endl;
		
	if (this->_type == 1 || this->_type == 2 || this->_floatType == (int)this->_floatType)
		std::cout << "double Value : " << this->_doubleType << ".0" << std::endl;
	else 
		std::cout << "double Value : " << this->_doubleType << std::endl;
}

void Cast::CharToOther(){
	this->_intType = static_cast<int>(this->_charType);
	this->_floatType = static_cast<float>(this->_charType);
	this->_doubleType = static_cast<double>(this->_charType);
}

void Cast::IntToOther()
{
	this->_charType = static_cast<char>(this->_intType);
	this->_floatType = static_cast<float>(this->_intType);
	this->_doubleType = static_cast<double>(this->_intType);
}

void Cast::FloaToOther(){
	this->_intType = static_cast<int>(this->_floatType);
	this->_charType = static_cast<char>(this->_floatType);
	this->_doubleType = static_cast<double>(this->_floatType);
}

void Cast::DoubleToOther(){
	this->_intType = static_cast<int>(this->_doubleType);
	this->_floatType = static_cast<float>(this->_doubleType);
	this->_charType = static_cast<char>(this->_doubleType);
}
