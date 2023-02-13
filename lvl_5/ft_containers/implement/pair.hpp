#ifndef PAIR_HPP
#define PAIR_HPP

#include <iostream>
#include <string>

namespace ft{
   template <class T1, class T2>
    class pair
    {
        public:
            // Constructors
            pair() : first() , second() {
            }
            pair(const T1 &a, const T2 &b) : first(a) , second(b) {
            }
            pair(const pair &copy): first(copy.first), second(copy.second) {}

            template <class U, class V>
            pair(const pair< U , V > &copy): first(copy.first), second(copy.second){
            }
            ~pair(){
            }
            pair & operator=(const pair &assign){
                if (this !=  &assign){
                    this->first = assign.first;
                    this->second = assign.second;
                }
                return *this;
            }

        public:
            T1 first;
            T2 second;
    };
    
    template <class T1, class T2>
    bool operator==(const pair<T1, T2> &p1, const pair<T1, T2> &p2){
        return (p1.first == p2.first && p1.second == p2.second);
    }

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &p1, const pair<T1, T2> &p2){
        std::cout << "operator!= called" << std::endl;
        return !(p1 == p2);
    }

    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &p1, const pair<T1, T2> &p2){
        return (p1.first < p2.first || (p1.first == p2.first &&  p1.second < p2.second));
    }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &p1, const pair<T1, T2> &p2){
        return (p1.first <= p2.first);
    }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &p1, const pair<T1, T2> &p2){
        return !(p1 <= p2);
    }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &p1, const pair<T1, T2> &p2){
        return !(p1 < p2);
    }

    template <class T1, class T2>
    pair<T1,T2> make_pair (T1 x, T2 y){
        return ( pair<T1,T2>(x,y) );
    }
    
}

#endif