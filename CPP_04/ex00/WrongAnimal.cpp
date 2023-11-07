#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal default constructor called" << std::endl;
    this->_type = "--no type--";
}

WrongAnimal::WrongAnimal(const WrongAnimal& toCopy) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = toCopy;
}

void WrongAnimal::operator=(const WrongAnimal& src) {
     std::cout << "WrongAnimal equal operator called" << std::endl;
    if (this == &src)
        return ;
    this->_type = src._type;
}

void    WrongAnimal::makeSound() const {
    std::cout << getType() << " makes a wrong animal sound" << std::endl;
}

const std::string    WrongAnimal::getType() const {
    return this->_type;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal Destructor called" << std::endl;
}
