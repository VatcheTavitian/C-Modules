#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed = src.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
//	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed;
}

void Fixed::setRawBits(int const raw) {
//	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed = raw;
}

Fixed::Fixed(const int int_n)  {
	std::cout << "Int constructor called" << std::endl;
	setRawBits(int_n << Fixed::_fBits);
}
Fixed::Fixed(const float float_n) {
	std::cout << "Float constructor called" << std::endl;
	setRawBits((int)roundf(float_n * ( 1 <<  Fixed::_fBits)));
}

float Fixed::toFloat(void) const {
	return (float)this->getRawBits() / (float)(1 << Fixed::_fBits);
}

int Fixed::toInt(void) const {
	return (getRawBits() >> Fixed::_fBits);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& src) {
	return (stream << src.toFloat());
}