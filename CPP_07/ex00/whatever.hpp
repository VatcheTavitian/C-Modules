#ifndef __WHATEVER_HPP__
#define __WHATEVER_HPP__

# include <iostream>

template<typename T>
void swap(T& a, T& b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<typename T>
T& min(T& a, T& b) {
    if (a < b)
        return (a);
    else
        return (b);
}

template<typename T>
T& max(T& a, T& b) {
    if (a >= b)
        return (a);
    else
        return (b);
}

#endif