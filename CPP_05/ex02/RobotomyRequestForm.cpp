#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy", 72, 45) {
	this->_target = target;
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& toCopy) :AForm(toCopy) {
	*this = toCopy;
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
	std::cout << "RobotomyRequestForm equal operator called" << std::endl;
	if (this == &src)
		return (*this);
	AForm::operator=(src);
	this->_target = src._target;
	return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void  RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_execGrade)
		throw AForm::GradeTooLowException();
	std::cout << "* Robot makes drilling noises *" << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->getTarget() <<" has been robotomized successfully!" << std::endl;
	else
		std::cout << this->getTarget() <<" robotomy unsuccessful..." << std::endl;
}
