#include "ScalarConverter.hpp"
#include <limits>
int main(int argc, char **argv) {
	if (argc != 2)
		std::cout << "One argument required" << std::endl;
	else {
		if (static_cast<std::string>(argv[1]).length() == 0)
			std::cout << "Input string cannot be empty" << std::endl;
		else
			ScalarConverter::convert(argv[1]);
	}

	// Test cases
	// ScalarConverter::convert("nan");
	// ScalarConverter::convert("-inf");
	// ScalarConverter::convert("+inff");
	// std::cout << '\n';
	// ScalarConverter::convert("1.79769e+308"); // DOUBLE MAX
	// std::cout << '\n';
	// ScalarConverter::convert("1.79769e+309"); // DOUBLE MAX + 1
	// std::cout << '\n';
	// ScalarConverter::convert("42");
	// std::cout << '\n';
	// ScalarConverter::convert("-77.54");
	// std::cout << '\n';
	// ScalarConverter::convert("A");
	// std::cout << '\n';
	// ScalarConverter::convert("");
	// std::cout << '\n';

}