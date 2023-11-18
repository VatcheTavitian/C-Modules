#include "Form.hpp"

Form::Form() :
	_name("default"),
	_signed(false),
	_signGrade(1),
	_execGrade(1) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, int signGrade, int execGrade) :
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade){
	std::cout << "Form constructor called" << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Form::Form(const Form& toCopy) :
	_name(toCopy._name),
	_signed(toCopy._signed),
	_signGrade(toCopy._signGrade),
	_execGrade(toCopy._execGrade) {
	std::cout << "Form copy constructor called" << std::endl;
	*this = toCopy;
}

// The only non const attribute you can assign is bool _signed... 
// As such copy constructor calls constructor with toCopy attributes...
Form& Form::operator=(const Form& src) {
	std::cout << "Form equal operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_signed = src._signed;
	return *this;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

const std::string& 	Form::getName() const {
	return (this->_name);
}
bool				Form::getSigned() const {
	return (this->_signed);
}

int			Form::getSignGrade() const {
	return (this->_signGrade);
}

int			Form::getExecGrade() const {
	return (this->_execGrade);
}

void		Form::beSigned(Bureaucrat& b) {
	if (this->getSignGrade() < b.getGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (!this->_signed) {
		this->_signed = true;
	} else {
		std::cout << "Form has already been signed" << std::endl;
	}
}


std::ostream& operator<<(std::ostream& lhs, const Form& rhs) {
	lhs << rhs.getName() 	<< " " 
	<< rhs.getSigned()  	<< " " 
	<< rhs.getSignGrade()  	<< " " 
	<< rhs.getExecGrade()  	<< " " ;
	return (lhs);
}
