#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
#include "WrongAnimal.hpp"
# include <string>

class WrongCat: public WrongAnimal 
{
	public: 
		// Constructors
		WrongCat();
		WrongCat(const WrongCat &copy);
		WrongCat(std::string type);
		
		// Destructor
		~WrongCat();
		
		// Operators
		WrongCat & operator=(const WrongCat &assign);


		void makeSound()const;
};

#endif