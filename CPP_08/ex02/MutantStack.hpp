#ifndef __MUTANTSTACK_HPP__
# define __MUTANTSTACK_HPP__

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <forward_list>
# include <array>
# include <deque>
# include <stack>


template <typename T>
class MutantStack: public std::stack<T> {
    public:

        MutantStack() : std::stack<T>() {std::cout << "MutantStack constructor called" << std::endl;};
        MutantStack(const MutantStack& src) : std::stack<T>(src) {std::cout << "MutantStack copy constructor called" << std::endl;};
        MutantStack& operator=(const MutantStack& toCopy) {
            if (this == &toCopy)
                return *this;
            static_cast<std::stack<T>&>(*this) = static_cast<const std::stack<T>&>(toCopy);
            return (*this);
        }
        ~MutantStack() {std::cout << "MutantStack destructor called" << std::endl; };

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin() {
            return std::stack<T>::c.begin();
        };

        iterator end() {
            return std::stack<T>::c.end();
        };

};

#endif