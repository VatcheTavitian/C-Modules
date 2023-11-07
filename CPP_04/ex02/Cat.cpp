#include "Cat.hpp"
#include "Brain.hpp"


Cat::Cat() : Animal("Cat") {
    std::cout << "Cat default constructor called" << std::endl;
    this->_brain = new Brain();
}

Cat::Cat(const Cat& toCopy) : Animal(toCopy)  {
    std::cout << "Cat copy constructor called" << std::endl;
    this->operator=(toCopy);
}

Cat& Cat::operator=(const Cat& src) {
    std::cout << "Cat equal operator called" << std::endl;
    if (this == &src)
        return (*this);
    this->_type = src._type;
    delete this->_brain;
    this->_brain = new Brain(*src._brain);

    return (*this);
}

void    Cat::makeSound() const {
    std::cout << "Cat makes a sound - 'MEOW!!'" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat Destructor called" << std::endl;
    delete this->_brain;
}
