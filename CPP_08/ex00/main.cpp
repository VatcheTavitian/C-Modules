#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <deque>

int main() {

    // Create containers
    std::vector<int> v;
    std::array<int, 5> a;
    std::list<int> l;
    std::deque<int> d;
  

    // Populate containers
    for (size_t i = 0; i < a.size(); i++) {
        a[i] = i * i;
        v.push_back(i * i);
        l.push_back(i * i);
        d.push_back(i * i);
    }

  

    std::cout << "Vector values" << std::endl;
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
        std::cout << *it << " in vector" << std::endl;
    std::cout << "\n" << std::endl;

    std::cout << "Array values" << std::endl;
    for (size_t i = 0; i < a.size(); i++)
       std::cout <<  a[i] << " in array position " << i << std::endl;
     std::cout << "\n" << std::endl;

    std::cout << "Look for 33 in vector" << std::endl;
    try {
        easyfind(v, 33);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Look for 33 in array" << std::endl;
    try {
        easyfind(a, 33);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Look for 4 in list" << std::endl;
    try {
        easyfind(l, 4);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Look for 4 in deque" << std::endl;
    try {
        easyfind(d, 4);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}