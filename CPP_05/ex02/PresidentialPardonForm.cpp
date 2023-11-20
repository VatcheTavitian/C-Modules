#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presedential", 72, 45) {
	this->_target = target;
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& toCopy) :AForm(toCopy) {
	*this = toCopy;
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
	std::cout << "PresidentialPardonForm equal operator called" << std::endl;
	if (this == &src)
		return (*this);
	AForm::operator=(src);
	this->_target = src._target;
	return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const{
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_execGrade)
		throw AForm::GradeTooLowException();
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	
}


