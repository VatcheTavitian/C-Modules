#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>
#include <iostream>

Base * generate(void) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(1,3);
    int randomIndex = distribution(rng);

    switch (randomIndex) {
        case(1):
            return(new A);
        case(2):
            return(new B);
        case(3):
            return(new C);
    }
    return (NULL);
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Object is of A type" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Object is of B type" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Object is of C type" << std::endl;
    else 
        std::cout << "Type Unknown" << std::endl;
}

void identify(Base& p) {
    try  {
        A &a = dynamic_cast<A &>(p);
        std::cout << "Object is of A type" << std::endl;
        (void) a;
    }
    catch (const std::exception &e) {
        try  {
            B &b = dynamic_cast<B &>(p);
            std::cout << "Object is of B type" << std::endl;
            (void) b;
        }
        catch (const std::exception &e) {
            try  {
            C &c = dynamic_cast<C &>(p);
            std::cout << "Object is of C type" << std::endl;
            (void) c;
            }
            catch (const std::exception &e) {
                std::cout << "Object is of unknown type" << std::endl;
            }
        }

    }
  
        
   
}