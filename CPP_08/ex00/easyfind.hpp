#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

# include <iostream>
# include <algorithm>

class NotFound: public std::exception {
    private:
        virtual const char* what() const throw() {
            return "Error: Number Not Found In Container";
        }
};

template<typename T>
typename T::iterator easyfind(T& cont, int n) {
 
    typename T::iterator it;
    it = std::find(cont.begin(), cont.end(), n);

    if (it == cont.end())
        throw (NotFound());
    std::cout << "Found " << *it << std::endl;
    return (it);

}

#endif