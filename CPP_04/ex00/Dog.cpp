#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog default constructor called" << std::endl;
    this->_type = "Dog";
}

Dog::Dog(const Dog& toCopy) : Animal(toCopy) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = toCopy;
}
Dog& Dog::operator=(const Dog& src) {
     std::cout << "Dog equal operator called" << std::endl;
    if (this == &src)
        return (*this);
    this->_type = src._type;
    return (*this);
}

void    Dog::makeSound() const {
    std::cout << "Dog makes a sound - 'WOOF!!'" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
}
