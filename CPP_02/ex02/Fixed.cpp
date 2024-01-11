#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& src)  {
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

bool Fixed::operator>(const Fixed& src) const{
	std::cout << "Greater than operator called" << std::endl;
	if (this->getRawBits() > src.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& src) const {
	std::cout << "Less than operator called" << std::endl;
	if (this->getRawBits() < src.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& src) const {
	std::cout << "Greater than or equal to operator called" << std::endl;
	if (this->getRawBits() >= src.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& src) const {
	std::cout << "Less than or equal to operator called" << std::endl;
	if (this->getRawBits() <= src.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& src) const {
	std::cout << "Equal to operator called" << std::endl;
	if (this->getRawBits() == src.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& src) const {
	std::cout << "Not equal to operator called" << std::endl;
	if (this->getRawBits() != src.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed& src) const {
	std::cout << "Plus operator called" << std::endl;
	return(Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(const Fixed& src) const {
	std::cout << "Minus operator called" << std::endl;
	return(Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(const Fixed& src) const {
	std::cout << "Multiply operator called" << std::endl;
	return(Fixed(this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(const Fixed& src) const {
	std::cout << "Divide operator called" << std::endl;
	return(Fixed(this->toFloat() / src.toFloat()));
}

Fixed Fixed::operator++() {
	std::cout << "Pre Increment Calc Called" << std::endl;
	this->_fixed++;
	return (*this);
};

Fixed Fixed::operator--() {
	std::cout << "Pre Decrement Calc Called" << std::endl;
	this->_fixed--;
	return (*this);
};

Fixed Fixed::operator++(int) {
	std::cout << "Post Increment Calc Called" << std::endl;
	Fixed	tmp(*this);
	this->_fixed++;
	return (tmp);
};

Fixed Fixed::operator--(int) {
	std::cout << "Post Decrement Calc Called" << std::endl;
	Fixed	tmp(*this);
	this->_fixed--;
	return (tmp);
};

Fixed&	Fixed::min(Fixed& a, Fixed& b)  {
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)  {
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)  {
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max( const Fixed& a, const Fixed& b)  {
	if (a > b)
		return (a);
	return (b);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& src) {
	return (stream << src.toFloat());
}