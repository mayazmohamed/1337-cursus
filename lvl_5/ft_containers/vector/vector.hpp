#ifndef VECTOR_HPP
#define VECTOR_HPP

# include "stdexcept"
# include <iostream>
# include <string>

#include "../implement/enable_if.hpp"
#include "../implement/equal.hpp"
#include "../implement/is_integral.hpp"
#include "../implement/iterator.hpp"
#include "../implement/iterator_traits.hpp"
#include "../implement/lexicographical_compare.hpp"

namespace ft{
    template < class T, class Alloc = std::allocator<T> >
    class vector
{
public:
        typedef T value_type;
	    typedef Alloc allocator_type;
	    typedef typename allocator_type::reference reference;
	    typedef typename allocator_type::const_reference const_reference;
	    typedef typename allocator_type::pointer pointer;
	    typedef typename allocator_type::const_pointer const_pointer;

	    typedef iterators<pointer> iterator;
	    typedef iterators<const_pointer> const_iterator;	
	    typedef reverse_iterator<const_iterator> const_reverse_iterator;
	    typedef reverse_iterator<iterator> reverse_iterator;
	    typedef std::size_t size_type;

        explicit vector (const allocator_type& alloc = allocator_type()){
           _size = 0;
            _capacity = 0;
            arr = nullptr;
            this->alloc = alloc;
        }

        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
            this->alloc = alloc;
			_size = n;
			this->_capacity = n;
            arr = this->alloc.allocate(n);
            for (size_t i = 0; i < n; i++)
                arr[i] = val;
        }

        template <class InputIterator>
         vector (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value , InputIterator>::type last, 
            const allocator_type& alloc = allocator_type()){
                this->alloc = alloc;
                if (last <= first)
                    return;
               _size = last - first;
				_capacity = last - first;
				this->alloc = alloc;
				arr = this->alloc.allocate(_capacity);
				int i = 0;
				for (InputIterator it = first ; it != last ; it++)
					arr[i++] = *it;
         }

        vector (const vector& x){
			_capacity = 0;
            *this = x;
        }

        ~vector()
		{
			alloc.deallocate(arr, _capacity);
			arr->~value_type();
			_capacity.~size_type();
			_size.~size_type();
			alloc.~allocator_type();
		}

        vector& operator= (const vector& x){
            if (this != &x){
                if (_capacity < x._capacity)
					if (_capacity > 0) 
				    	alloc.deallocate(arr, _capacity);
				    this->alloc = x.alloc;
				    arr = this->alloc.allocate(x._size);
                    _capacity = x._size;
                }
               _size = x._size;
				for (size_type i = 0; i <_size;  i++)
					arr[i] = x.arr[i];
				return *this;
        }

        //Iterators:

        iterator begin(){
			return arr;
		}

		const_iterator begin() const{
			return arr;
		}

		iterator end(){
			return arr + _size;
		}

		const_iterator end() const{
			return arr + _size;
		}

		reverse_iterator rbegin(){
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const{
			return const_reverse_iterator(end());
		}

		reverse_iterator rend(){
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend() const{
			return const_reverse_iterator(begin());
		}



      	size_type size() const
        {
            return _size;
        }

      	size_type max_size() const{
            return alloc.max_size();
        }


        void resize (size_type n, value_type val = value_type()){
            T *tmp;
            if (_size == n)
					return ;
			else if (n <_size) {
				for (size_type i = n ; i <_size ; i++)
					arr[i].~value_type();
				_size = n;
			}
            else {
				if (this->_capacity * 2 <= n)
					this->_capacity = n;
				else if (this->_capacity < n && this->_capacity * 2 > n)
					this->_capacity *= 2;
                tmp = this->alloc.allocate(this->_capacity);
				for (size_type i = 0; i <_size ; i++)
					tmp[i] = arr[i];
				for (size_type i =_size; i < n ; i++)
					tmp[i] = val;
				alloc.deallocate(arr,_size);
				_size = n;
				arr = tmp;
            }
        }

		

      size_type capacity() const{
            return this->_capacity;
        }

        bool empty() const
        {
            return (_size == 0);
        }
        
        void reserve (size_type n){
            T *tmp;
            if (this->_capacity >= n)
                return;
            if (this->_capacity * 2 <= n)
					this->_capacity = n;
			else if (this->_capacity < n && this->_capacity * 2 > n)
				this->_capacity *= 2;
            tmp = this->alloc.allocate(this->_capacity);
			for (size_type i = 0; i <_size ; i++)
				tmp[i] = arr[i];
			alloc.deallocate(arr,_size);
			_size = n;
			arr = tmp;
        }

        reference operator[] (size_type n)
        {
            return arr[n];
        }

        const_reference operator[] (size_type n) const
        {
            return arr[n];
        }

        reference at (size_type n){
            if (n >= _size)
                throw std::out_of_range("Vector");
            return arr[n];
        }

        const_reference at (size_type n) const{
            if (n >= this->size)
                throw std::out_of_range("Vector");
            return arr[n];
        }

        reference front(){
            if (_size == 0)
                throw std::out_of_range("Vector");
            return arr[0];
        }

        const_reference front() const{
            if (this->size == 0)
                throw std::out_of_range("Vector");
            return arr[0];
        }

        reference back(){
            if (_size == 0)
                throw std::out_of_range("Vector");
            return arr[_size];
        }

        const_reference back() const{
            if (this->size == 0)
                throw std::out_of_range("Vector");
            return arr[_size];
        }
    
        void assign (size_type n, const value_type& val){
            if (_capacity >= n) {
				for (size_type i = 0 ; i < n ; i++)
					arr[i] = val;
			} else {
				_capacity = n;
				alloc.deallocate(arr,_size);
				arr = alloc.allocate(_capacity);
				for (size_type i = 0; i < n ; i++)
					arr[i] = val;
			}
			_size = n;
        }

        template <class InputIterator>
  		void assign (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value , InputIterator>::type last) {
			int j = 0;
			if (last < first)
                throw std::range_error("Vector");
			if ((long long)_capacity >= last - first){
				for (InputIterator it = first ; it < last ; it++)
					arr[j++] = *it;
			} else {
				_capacity = last - first;
				alloc.deallocate(arr,_size);
				arr = alloc.allocate(_capacity);
				for (InputIterator it = first ; it < last ; it++)
					arr[j++] = *it;
			}
			_size = last - first;
		}

        void push_back (const value_type& val){
            T* tmp;
			if (_size < _capacity) 
				arr[_size++] = val;
			else {
				if (_capacity == 0)
					_capacity++;
				else
					_capacity *= 2;
				tmp = alloc.allocate(_capacity);
			    for (size_type i = 0; i <_size ; i++)
			        tmp[i] = arr[i];
			    alloc.deallocate(arr,_size);
			   _size++;
			    arr = tmp;
			}
		}

        void pop_back() {
			//TODO size - 1
			arr[_size - 1].~value_type();
			_size--;
		}

        iterator insert (iterator position, const value_type& val){
			size_type pos;
			if (_size < _capacity) {
				pos =_size - 1;
				for (iterator it = end() - 1 ; it > position ; it--) {
					arr[pos + 1] = arr[pos];
					pos--;
				}
				arr[pos] = val;			
			} else {
				value_type* tmp;
				pos = 0;
				if (_capacity == 0)
					_capacity++;
				else
					_capacity *= 2;
				tmp = alloc.allocate(_capacity);
				for (iterator it = begin() ; it < position ; it++) {
					tmp[pos] = arr[pos];
					pos++;
				}
				tmp[pos] = val;
				size_type i = pos + 1;
				for (iterator it = position + 1 ; it <= end() ; it++) {
					tmp[i] = arr[i - 1];
					i++;
				}
				alloc.deallocate(arr,_size);
				arr = tmp;
			}
			_size++;
			return begin() + pos;
		}

        void insert (iterator position, size_type n, const value_type& val){
          size_type pos;
			if (_size + n < _capacity) {
				pos =_size - 1;
				for (iterator it = end() - 1 ; it > position ; it--) {
					arr[pos + n] = arr[pos];
					pos--;
				}
				for (size_type i = 0 ; i < n ; i++)
					arr[pos + i] = val;			
			} else {
				value_type* tmp;
				pos = 0;
				if (_size + n <= _capacity * 2)
					_capacity *= 2;
				else
					_capacity =_size + n;
				tmp = alloc.allocate(_capacity);
				for (iterator it = begin() ; it < position ; it++) {
					tmp[pos] = arr[pos];
					pos++;
				}
				for (size_type i = 0 ; i < n ; i++)
					tmp[pos + i] = val;
				size_type i = pos + n;
				for (iterator it = position + 1 ; it <= end() ; it++) {
					tmp[i] = arr[i - n];
					i++;
				}
				alloc.deallocate(arr,_size);
				arr = tmp;
			}
			_size += n;
        }

        template <class InputIterator>
    	void insert (iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value , InputIterator>::type last)
		{
			if (last < first)
                throw std::range_error("Vector");
			size_type pos;
			size_type n = (last - first);
			if (last - first < 0)
				return ;
			if (_size + n < _capacity) {
				pos =_size - 1;
				for (iterator it = end() - 1 ; it >= position ; it--) {
					arr[pos + n] = *(it);
					if (pos)
						pos--;
				}
				iterator it = first;
				for (size_type i = 0 ; i < n ; i++)
					arr[pos + i] = *(it++);		
			} else {
				value_type* tmp;
				pos = 0;
				if (_size + n <= _capacity * 2)
					_capacity *= 2;
				else
					_capacity =_size + n;
				tmp = alloc.allocate(_capacity);
				for (iterator it = begin() ; it < position ; it++) {
					tmp[pos] = arr[pos];
					pos++;
				}
				iterator it = first;
				for (size_type i = 0 ; i < n ; i++)
					tmp[pos + i] = *(it++);
				size_type i = pos + n;
				for (iterator it = position + 1 ; it <= end() ; it++) {
					tmp[i] = arr[i - n];
					i++;
				}
				alloc.deallocate(arr,_size);
				arr = tmp;
			}
			_size += n;
		}


		iterator erase (iterator position){
			iterator it = position;
			if (it < begin() || it > end())
				return position;
			for (; it < end() - 1 ; it++) {	
				*it = *(it + 1);
			}
			_size--;
			return position;
		}


		iterator erase (iterator first, iterator last){
			if (last < first)
                throw std::range_error("Vector");
			size_type n = last - first;
			for (iterator it = first ; it < last ; it++) {
				if (it + n >= end())
					break ;
				*(it) = *(it + n);
			}
			if (n > 0)
				_size -= n;
			for (iterator it = last ; it < end() ; it++) {
				*(it) = *(it + n);
			}
			return first;
		}

		void swap (vector& x){
			value_type* tmp_data = x.arr;
			size_type tmp_size = x._size;
			size_type tmp_capacity = x._capacity;
			x.arr = this->arr;
			x._capacity = this->_capacity;
			x._size = _size;
			this->arr = tmp_data;
			_size = tmp_size;
			this->_capacity = tmp_capacity;
		}

		void clear(){
			for (size_type i = 0; i <_size; i++)
				arr[i] =~value_type();
			_size = 0;
		}

		allocator_type get_allocator() const{
			return alloc;
		}

private:
        T *arr;
        size_type _size;
        size_type _capacity;
        Alloc alloc;
};
	template <class T, class Alloc>
  		bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
			if (lhs.size() != rhs.size() || !ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
				return false;
			return true;
		}
	
	template <class T, class Alloc>
  		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			  return !(lhs == rhs);
		  }
		  
	template <class T, class Alloc>
  		bool operator< (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

	template <class T, class Alloc>
  		bool operator> (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
			return rhs < lhs;
		}

	template <class T, class Alloc>
  		bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
			return !(rhs < lhs);
		}

	template <class T, class Alloc>
  		bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
			return !(lhs <= rhs);
		}
		
	template <class T, class Alloc>
  		void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y) {
			  x.swap(y);
		}

}


#endif