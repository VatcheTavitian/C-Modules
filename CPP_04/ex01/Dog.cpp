#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal () {
    std::cout << "Dog default constructor called" << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
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
    delete this->_brain;
    this->_brain = new Brain(*src._brain);
    return (*this);
}

void    Dog::makeSound() const {
    std::cout << "Dog makes a sound - 'WOOF!!'" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
    delete this->_brain;
}
