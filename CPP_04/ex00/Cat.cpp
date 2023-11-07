#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat default constructor called" << std::endl;
    this->_type = "Cat";
}

Cat::Cat(const Cat& toCopy) : Animal(toCopy) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = toCopy;
}
Cat& Cat::operator=(const Cat& src) {
     std::cout << "Cat equal operator called" << std::endl;
    if (this == &src)
        return (*this);
    this->_type = src._type;
    return (*this);
}

void    Cat::makeSound() const {
    std::cout << "Cat makes a sound - 'MEOW!!'" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat Destructor called" << std::endl;
}
