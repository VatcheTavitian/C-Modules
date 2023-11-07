#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal default constructor called" << std::endl;
    this->_type = "--no type--";
}

Animal::Animal(const Animal& toCopy) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = toCopy;
}

void Animal::operator=(const Animal& src) {
     std::cout << "Animal equal operator called" << std::endl;
    if (this == &src)
        return ;
    this->_type = src._type;
}

void    Animal::makeSound() const {
    std::cout << "Animal makes a sound" << std::endl;
}

const std::string    Animal::getType() const {
    return this->_type;
}

Animal::~Animal() {
    std::cout << "Animal Destructor called" << std::endl;
}
