#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
template <typename type>

class Array
{
	public:
		// Constructors
		Array();
		Array(const Array<type> &copy);
		Array(unsigned int size);
		int size();
		
		// Destructor
		~Array();
		
		// Operators
		Array & operator=(const Array<type> &assign);
		type &	operator[]( int index );
		class Exception : public std::exception {
		public:
			const char *what() const throw(){
				return "index out of bound";
			}
	};
		
	private:
		unsigned int _size;
		type *_a;
		
};
template <typename type>
// Constructors
Array<type>::Array()
{
	_size = 0;
	_a = nullptr;
	std::cout << "\e[0;33mDefault Constructor called of Array\e[0m" << std::endl;
}

template <typename type>
Array<type>::Array(const Array &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Array\e[0m" << std::endl;
}

template <typename type>
Array<type>::Array(unsigned int size)
{
	this->_size = size;
	this->_a = new type[size];
	std::cout << "\e[0;33mFields Constructor called of Array\e[0m" << std::endl;
}


// Destructor
template <typename type>
Array<type>::~Array()
{
	std::cout << "\e[0;31mDestructor called of Array\e[0m" << std::endl;
	if (this->_size > 0)
		delete [] this->_a;
}


// Operators
template <typename type>
Array<type> & Array<type>::operator=(const Array<type> &a)
{
	if (this != &a){
		if (this->_size > 0)
			delete [] this->_a;
		this->_a = new type[a._size];
		for (unsigned int i = 0; i < a._size; i++)
			this->_a[i] = a._a[i];
		this->_size = a._size;
		
	}
	return *this;
}

template <class type>
type& Array<type>::operator[](int index)
{
    if (index < 0 || index >= (int)this->_size)
        throw Array<type>::Exception();
    return this->_a[index];
}

template <class type>
int Array<type>::size(){
	return this->_size;
}

#endif