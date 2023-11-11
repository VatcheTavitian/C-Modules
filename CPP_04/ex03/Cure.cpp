#include "Cure.hpp"
#include "AMateria.hpp"


Cure::Cure()
{
    std::cout << "Cure constructor called" << std::endl;
    this->_type = "Cure";
}

Cure::Cure(const Cure& toCopy) {
     std::cout << "Cure copy constructor called" << std::endl;
     *this = toCopy;
}

Cure&    Cure::operator =(const Cure& src) {
    if (this == &src)
        return (*this);
    this->_type = src._type;
    return (*this);
}

AMateria* Cure::clone() const {
    return (new Cure(*this));
}

std::string const& Cure::getType() const {
    return (this->_type);
}

void    Cure::setType(const std::string newType) {
    this->_type = newType;
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure()
{
    std::cout << this->_type << " destructor called" << std::endl;
}