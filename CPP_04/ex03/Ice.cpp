#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice()  {
    std::cout << "Ice constructor called" << std::endl;
    this->_type = "Ice";
}

Ice::Ice(const Ice& toCopy) {
     std::cout << "Ice copy constructor called" << std::endl;
     *this = toCopy;
}

Ice&    Ice::operator =(const Ice& src) {
    if (this == &src)
        return (*this);
    this->_type = src._type;
    return (*this);
}

AMateria* Ice::clone() const {
    return (new Ice(*this));
}

std::string const& Ice::getType() const {
    return (this->_type);
}

void    Ice::setType(const std::string newType) {
    this->_type = newType;
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice()
{
    std::cout << this->_type << " destructor called!" << std::endl;
}