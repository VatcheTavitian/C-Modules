#include "AMateria.hpp"

AMateria::AMateria() {
    // this->_type = "Default type";
    // std::cout << _type << " material constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) {
    this->_type = type;
    std::cout << _type << " material constructor called" << std::endl;
}


AMateria::AMateria(const AMateria& toCopy) {
    std::cout << this->_type << " material copy constructor called" << std::endl;
    *this = toCopy;
}

AMateria& AMateria::operator=(const AMateria& src) {
    std::cout << this->_type << " material equal operator overloader called" << std::endl;
    if (this == &src)
        return (*this);
    this->_type = src._type;
    return (*this);
}

AMateria::~AMateria() {
     std::cout << _type << "Default material destructor called" << std::endl;
}