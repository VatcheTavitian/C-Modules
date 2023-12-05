#include "ScalarConverter.hpp"
#include <limits>
int main() {

	ScalarConverter::convert("nan");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("+inff");
	std::cout << '\n';
	ScalarConverter::convert("1.79769e+308"); // DOUBLE MAX
	std::cout << '\n';
	ScalarConverter::convert("1.79769e+309"); // DOUBLE MAX + 1
	std::cout << '\n';
	ScalarConverter::convert("42");
	std::cout << '\n';
	ScalarConverter::convert("-77.54");
	std::cout << '\n';
	ScalarConverter::convert("A");
	std::cout << '\n';
	ScalarConverter::convert("hello");
	std::cout << '\n';
	// ScalarConverter::convert("nan");
	// ScalarConverter::convert("42f");
	// ScalarConverter::convert("-32f");
}