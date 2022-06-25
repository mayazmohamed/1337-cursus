#ifndef VECTOR_HPP
#define VECTOR_HPP

# include "stdexcept"
# include <iostream>
# include <string>

#include "implement/enable_if.hpp"
#include "implement/equal.hpp"
#include "implement/is_integral.hpp"
#include "implement/iterator.hpp"
#include "implement/iterator_traits.hpp"
#include "implement/lexicographical_compare.hpp"

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

        vector (const allocator_type& alloc = allocator_type()){
            size = 0;
            capacity = 0;
            arr = nullptr;
            this->alloc = alloc;
        }

        vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
            this->alloc = alloc;
			this->size = n;
			this->capacity = n;
            arr = alloc.allocate(n);
            for (size_t i = 0; i < n; i++)
                arr[i] = val;
        }

        template <class InputIterator>
         vector (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value , InputIterator>::type last, 
            const allocator_type& alloc = allocator_type()){
                this->alloc = alloc;
                if (last <= first)
                    return;
                size = last - first;
				capacity = last - first;
				alloc = alloc;
				arr = alloc.allocate(capacity);
				int i = 0;
				for (InputIterator it = first ; it != last ; it++)
					arr[i++] = *it;
         }

        vector (const vector& x){
            *this = copy;
        }

        ~vector()
		{
			alloc.deallocate(_data, _capacity);
			arr->~value_type();
			capacity.~size_type();
			size.~size_type();
			alloc.~allocator_type();
		}

        vector& operator= (const vector& x){
            if (this != &x){
                if (x.size > capacity){
				    alloc.deallocate(arr, capacity);
				    alloc = x.alloc;
				    arr = alloc.allocate(x.size);
                    capacity = x.size;
                }
                size = x.size;
				for (size_type i = 0; i < _size ;  i++)
					arr[i] = x.arr[i];
			}
				return *this;
        }

        //Iterators:

        iterator begin(){
			return arr;
		}

		const_iterator cbegin() const {
			return arr;
		}

		iterator end(){
			return arr + _size;
		}

		const_iterator cend() const {
			return arr + _size;
		}

		reverse_iterator rbegin(){
			return arr + _size - 1;
		}

		const_reverse_iterator crbegin() const {
			return arr + _size - 1;
		}

		reverse_iterator rend(){
			return arr - 1;
		}

		const_reverse_iterator crend() const {
			return arr - 1;
		}


        size_type size() const
        {
            return size;
        }

        size_type max_size() const{
            return alloc.,ax_size();
        }


        void resize (size_type n, value_type val = value_type()){
            T *tmp;
            if (size == n)
					return ;
			if (n < size) {
				for (size_type i = n ; i < size ; i++)
					arr[i].~value_type();
				size = n;
			}
            else {
				if (this->capacity * 2 <= n)
					this->capacity = n;
				else if (this->capacity < n && this->capacity * 2 > n)
					this->capacity *= 2;
                tmp = this->alloc.allocator(this->capacity);
				for (size_type i = 0; i < size ; i++)
					tmp[i] = arr[i];
				for (size_type i = size; i < n ; i++)
					tmp[i] = val;
				alloc.deallocate(arr, size);
				size = n;
				arr = tmp;
            }
        }

        size_type capacity() const{
            return this->capacity;
        }

        bool empty() const
        {
            return (size == 0);
        }
        
        void reserve (size_type n){
            T *tmp
            if (this->capacity >= n)
                return;
            if (this->capacity * 2 <= n)
					this->capacity = n;
			else if (this->capacity < n && this->capacity * 2 > n)
				this->capacity *= 2;
            tmp = this->alloc.allocator(this->capacity);
			for (size_type i = 0; i < size ; i++)
				tmp[i] = arr[i];
			alloc.deallocate(arr, size);
			size = n;
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
            if (n >= this->size)
                throw std::out_of_range("Vector");
            return arr[n];
        }

        const_reference at (size_type n) const{
            if (n >= this->size)
                throw std::out_of_range("Vector");
            return arr[n];
        }

        reference front(){
            if (this->size == 0)
                return nullptr;
            return arr[0];
        }

        const_reference front() const{
            if (this->size == 0)
                return nullptr;
            return arr[0];
        }

        reference back(){
            if (this->size == 0)
                return nullptr;
            return arr[size];
        }

        const_reference back() const{
            if (this->size == 0)
                return nullptr;
            return arr[size];
        }

        template <class InputIterator>
        void assign (InputIterator first, InputIterator last){
            int j = 0;
            if (last < first)
                throw std::range_error("Vector");
			if ((long long)capacity >= last - first){
				for (InputIterator it = first ; it < last ; it++)
					arr[j++] = *it;
			} else {
				capacity = last - first;
				alloc.deallocate(arr, size);
				arr = alloc.allocate(capacity);
				for (InputIterator it = first ; it < last ; it++)
					arr[j++] = *it;
			}
			size = last - first;
        }
    
        void assign (size_type n, const value_type& val){
            if (capacity >= n) {
				for (size_type i = 0 ; i < n ; i++)
					arr[i] = val;
			} else {
				capacity = n;
				alloc.deallocate(arr, size);
				arr = alloc.allocate(capacity);
				for (size_type i = 0; i < n ; i++)
					arr[i] = val;
			}
			size = n;
        }

        template <class InputIterator>
  		void assign (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value , InputIterator>::type last) {
			int j = 0;
			if (last < first)
                throw std::range_error("Vector");
			if ((long long)capacity >= last - first){
				for (InputIterator it = first ; it < last ; it++)
					arr[j++] = *it;
			} else {
				capacity = last - first;
				alloc.deallocate(arr, size);
				arr = _alloc.allocate(capacity);
				for (InputIterator it = first ; it < last ; it++)
					arr[j++] = *it;
			}
			size = last - first;
		}

        void push_back (const value_type& val){
            T* tmp;
			if (size < capacity) 
				arr[size++] = val;
			else {
				if (capacity == 0)
					capacity++;
				else
					capacity *= 2;
				tmp = this->alloc.allocator(this->capacity);
			    for (size_type i = 0; i < size ; i++)
			        tmp[i] = arr[i];
			    alloc.deallocate(arr, size);
			    size = n;
			    arr = tmp;
			}
		}

        void pop_back() {
			arr[size].~value_type();
			size--;
		}

        iterator insert (iterator position, const value_type& val){
			size_type pos;
			if (size < capacity) {
				pos = size - 1;
				for (iterator it = end() - 1 ; it > position ; it--) {
					arr[pos + 1] = arr[pos];
					pos--;
				}
				arr[pos] = val;			
			} else {
				value_type* tmp;
				pos = 0;
				if (capacity == 0)
					capacity++;
				else
					capacity *= 2;
				tmp = alloc.allocate(capacity);
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
				alloc.deallocate(arr, size);
				arr = tmp;
			}
			size++;
			return begin() + pos;
		}

        void insert (iterator position, size_type n, const value_type& val){
            size_type pos;
			if (size + n < capacity) {
				pos = size - 1;
				for (iterator it = end() - 1 ; it > position ; it--) {
					arr[pos + n] = arr[pos];
					pos--;
				}
				for (size_type i = 0 ; i < n ; i++)
					arr[pos + i] = val;			
			} else {
				value_type* tmp;
				pos = 0;
				if (size + n <= capacity * 2)
					capacity *= 2;
				else
					capacity = size + n;
				tmp = alloc.allocate(capacity);
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
				alloc.deallocate(arr, size);
				arr = tmp;
			}
			size += n;
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
			if (size + n < capacity) {
				pos = size - 1;
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
				if (size + n <= capacity * 2)
					capacity *= 2;
				else
					capacity = size + n;
				tmp = alloc.allocate(capacity);
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
				alloc.deallocate(arr, size);
				arr = tmp;
			}
			size += n;
		}


		iterator erase (iterator position){
			iterator it = position;
			if (it < begin() || it > end())
				return position;
			for (; it < end() - 1 ; it++) {	
				*it = *(it + 1);
			}
			size--;
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
				size -= n;
			for (iterator it = last ; it < end() ; it++) {
				*(it) = *(it + n);
			}
			return first;
		}

		void swap (vector& x){
			value_type* tmp_data = x.arr;
			size_type tmp_size = x.size;
			size_type tmp_capacity = x.capacity;
			x.arr = this->arr;
			x.capacity = this->capacity;
			x.size = this->size;
			this->arr = tmp_data;
			this->size = tmp_size;
			this->capacity = tmp_capacity;
		}

		void clear(){
			for (size_type i = 0; i < size; i++)
				arr[i] =~value_type();
			size = 0;
		}

		allocator_type get_allocator() const{
			return alloc;
		}

private:
        T *arr;
        int size;
        int capacity;
        Alloc alloc;
};
	template <class T, class Alloc>
  		bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
			if (lhs.size() != rhs.size() || !ft::equal(lhs.cbegin(), lhs.cend(), rhs.cbegin()))
				return false;
			return true;
		}
	
	template <class T, class Alloc>
  		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			  return !(lhs == rhs);
		  }
		  
	template <class T, class Alloc>
  		bool operator< (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
			return (ft::lexicographical_compare(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend()));
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
			return !(lhs < rhs);
		}
		
	template <class T, class Alloc>
  		void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y) {
			  x.swap(y);
		}

}


#endif