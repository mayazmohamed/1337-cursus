#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "implement/enable_if.hpp"
#include "implement/equal.hpp"
#include "implement/is_integral.hpp"
#include "implement/iterator.hpp"
#include "implement/iterator_traits.hpp"
#include "implement/lexicographical_compare.hpp"

namespace ft{
    template < class T, class Alloc = std::allocator<T> >
    class Vector
{
        T *arr;
        int size;
        int capacity;
        Alloc alloc;
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
            arr = alloc.allocate(n);
            for (size_t i = 0; i < n; i++)
                arr[i] = val;
        }

        template <class InputIterator>
         vector (ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>, InputIterator first, InputIterator last, 
            const allocator_type& alloc = allocator_type()){
                this->alloc = alloc;
                if (last <= first)
                    return;
                size = last - first;
				capacity = last - first;
				alloc = alloc;
				arr = _alloc.allocate(_capacity);
				int i = 0;
				for (InputIterator it = first ; it != last ; it++)
					_data[i++] = *it;
         }


        vector(size_type size, const value_type& val = value_type())
			{
				size = size;
				capacity = size;
				arr = alloc.allocate(capacity);
				for (size_type i = 0; i < capacity ; i++)
					arr[i] = val;
			}


        vector (const vector& x){
            *this = copy;
        }

        ~vector(size_type size, const value_type& val = value_type())
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


        //Capacity:

        size_type size() const
        {
            return size;
        }

        size_type max_size() const{
            return alloc.,ax_size();
        }


        void resize (size_type n, value_type val = value_type()){
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
                
        }
        }








        bool empty() const
        {
            return (size == 0);
        }
        float capacity() const;
        void push_back(const T data)
        {
            if(size == capacity)
            {
                    capacity *= 2;
                    T *old_arr = arr;
                    arr = alloc.allocate(capacity);
                    for(int i = 0; i < size; i++)
                            arr[i] = old_arr[i];
                    alloc.deallocate(old_arr, size);
            }
            arr[size++] = data;
            return;
        }
        void pop()
        {
            if(empty())
                return;
            cs--;
        }
        reference operator [](const int i)
        {
            return arr[i];
        }
};
}


#endif