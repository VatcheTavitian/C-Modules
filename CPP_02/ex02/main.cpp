#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	//more tests
	std::cout << "a = " << a <<" b = " << b << std::endl;
	std::cout << "a + b should = 10.1094... result > \n" << a + b << std::endl;
	std::cout << "b - a should = 10.0938... result > \n" << b - a << std::endl;
	std::cout << "b - b - b should = -10.1016 ... result > \n" << (b - b - b)  << std::endl;
	std::cout << "b / a should = 1293 ... result > \n" << (b / a)  << std::endl;
	std::cout << "b == b should = 1/True... result > \n" << (b == b) << std::endl;
	std::cout << "b == a should = 0/False... result > \n" << (b == a) << std::endl;
	std::cout << "b > a should = 1/True... result > \n" << (b > a) << std::endl;
	std::cout << "b < a should = 0/False... result > \n" << (b < a) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	a = (a + b + b + b);
	std::cout << "a = " << a <<" b = " << b << std::endl;

	return 0;
}