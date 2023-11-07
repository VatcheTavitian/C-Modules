#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& toCopy) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = toCopy;
}

Brain&    Brain::operator=(const Brain& src) {
    std::cout << "Brain equal assignment called" << std::endl;
    if (this == &src)
        return (*this);
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = src._ideas[i];
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}