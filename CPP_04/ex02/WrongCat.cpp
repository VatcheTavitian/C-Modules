#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "WrongCat default constructor called" << std::endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& toCopy) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = toCopy;
}
void WrongCat::operator=(const WrongCat& src) {
     std::cout << "WrongCat equal operator called" << std::endl;
    if (this == &src)
        return ;
    this->_type = src._type;
}

// void    WrongCat::makeSound() const {
//     std::cout << "WrongCat makes a wrong sound" << std::endl;
// }

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor called" << std::endl;
}