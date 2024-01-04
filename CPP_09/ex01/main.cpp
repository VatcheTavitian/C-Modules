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

	// Check copy constructor works with deep copy
	// Move member variable _stack and constructor RPN() from private to public before testing
	// (void) argv;
	// RPN *rpn = new RPN();
	// rpn->_stack.push(5);
	// rpn->_stack.push(10);
	// rpn->_stack.push(15);
	// rpn->_stack.push(20);
	// std::cout << "RPN stack size should equal 4 | RPN stack size = " << rpn->_stack.size() << std::endl;
	// RPN *rpnCopy = new RPN(*rpn);
	// std::cout << "RPNCopy stack size should equal 4 | RPNCopy stack size = " << rpnCopy->_stack.size() << std::endl;
	// std::cout << "RPN stack size should equal 4 | RPN stack size = " << rpn->_stack.size() << std::endl;
	// delete(rpn);
	// delete(rpnCopy);
}