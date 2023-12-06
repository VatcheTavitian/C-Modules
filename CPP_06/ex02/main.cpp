#include "Base.hpp"
#include <iostream>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
    {
        Base* basePtr = generate();
        // std::cout << basePtr << std::endl;
        identify(basePtr);
        identify(*basePtr);
        delete basePtr;
    }

    // system("leaks ex02");
}