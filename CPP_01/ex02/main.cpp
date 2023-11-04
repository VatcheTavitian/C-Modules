#include <iostream>

int	main(void) {
	std::string		brain;
	std::string*	stringPTR;
	std::string&	stringREF = brain;

	brain = "HI THIS IS BRAIN";
	stringPTR = &brain;

	std::cout << "Memory address of str variable = ";
	std::cout << &brain << std::endl;
	std::cout << "Memory address of stringPTR = ";
	std::cout << stringPTR << std::endl;
	std::cout << "Memory address of stringREF = ";
	std::cout << &stringREF << std::endl;
	std::cout << std::endl;
	
	std::cout << "Value of str variable = ";
	std::cout << brain << std::endl;
	std::cout << "Value pointed to by stringPTR = ";
	std::cout << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF = ";
	std::cout << stringREF << std::endl;
}