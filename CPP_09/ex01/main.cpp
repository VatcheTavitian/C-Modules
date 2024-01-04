#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) 
		return std::cout << "Error: incorrect number of arguments" << std::endl, -1;
	try {
		RPN *rpn = new RPN(argv[1]);
		delete (rpn);
	} catch (RPN::InvalidSyntax& e) {
		std::cout << e.what() << std::endl;
	}

	
}