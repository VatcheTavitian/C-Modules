#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

Intern::Intern() {
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& toCopy) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = toCopy;
}

Intern& Intern::operator=(const Intern& src) {
	std::cout << "Intern equal assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string&name, const std::string& target) {
	std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresedentialPardonForm"};
	int i = 0;
	for (; i < 3 && forms[i] != name; i++);
	switch (i){
		case(0):
			std::cout << "Intern creates new ShrubberyCreationForm" << std::endl;
			return new ShrubberyCreationForm(target);
		case(1):
			std::cout << "Intern creates new RobotomyRequestForm" << std::endl;
			return new RobotomyRequestForm(target);
		case(2):
			std::cout << "Intern creates new PresedentialPardonForm" << std::endl;
			return new PresidentialPardonForm(target);
		default:
			throw Intern::FormDoesNotExist();
			return NULL;
		}
}

const char* Intern::FormDoesNotExist::what() const throw() {
	return "Error: Form Does Not Exist";
}
