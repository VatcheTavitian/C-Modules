#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;
	a.setRawBits(100);
	b.setRawBits(200);
	c.setRawBits(300);
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	// Check memory addresses are different
	std::cout << "Memory address of a = " << &a << std::endl;
	std::cout << "Memory address of b = " << &b << std::endl;
	std::cout << "Memory address of c = " << &c << std::endl;
	return 0;
}