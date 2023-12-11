#ifndef __ITER_HPP__
#define __ITER_HPP__

# include <iostream>

template<typename T>
void printFunction(T& value) {
    std::cout << value << " ";
    return ;
}

template<typename T>
void square(T& value) {
    std::cout << value * value << std::endl;
    return ;
}

template<typename T>
void iter(T *a, ssize_t len, void (*func)(T &)) {
    for (ssize_t i = 0; i < len; i++)
        func(a[i]);
    std::cout << std::endl;
}

#endif