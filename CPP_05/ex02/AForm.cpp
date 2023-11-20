#include "AForm.hpp"

AForm::AForm() :
	_name("default"),
	_signed(false),
	_signGrade(1),
	_execGrade(1) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, int signGrade, int execGrade) :
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade){
	std::cout << "AForm constructor called" << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(const AForm& toCopy) :
	_name(toCopy._name),
	_signed(toCopy._signed),
	_signGrade(toCopy._signGrade),
	_execGrade(toCopy._execGrade) {
	std::cout << "AForm copy constructor called" << std::endl;
	*this = toCopy;
}

AForm& AForm::operator=(const AForm& src) {
	std::cout << "AForm equal operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_signed = src._signed;
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

const std::string& 	AForm::getName() const {
	return (this->_name);
}
bool				AForm::getSigned() const {
	return (this->_signed);
}

int			AForm::getSignGrade() const {
	return (this->_signGrade);
}

int			AForm::getExecGrade() const {
	return (this->_execGrade);
}

void		AForm::beSigned(Bureaucrat& b) {
	if (this->getSignGrade() < b.getGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (!this->_signed) {
		this->_signed = true;
	} else {
		std::cout << "AForm has already been signed" << std::endl;
	}
}

const char*	AForm::GradeTooHighException::what() throw (){
	return "Execution Error: Grade Too High Exception";
}

const char*	AForm::GradeTooLowException::what() throw() {
	return "Execution Error: Grade Too Low Exception";
}

const char*	AForm::FormNotSignedException::what() throw() {
	return "Execution Error: Form Not Signed Exception";
}


void				AForm::setTarget(std::string target) {
	this->_target = target;
}
const std::string&			AForm::getTarget() const {
	return (_target);
}


std::ostream& operator<<(std::ostream& lhs, const AForm& rhs) {
	lhs << rhs.getName() 	<< " " 
	<< rhs.getSigned()  	<< " " 
	<< rhs.getSignGrade()  	<< " " 
	<< rhs.getExecGrade()  	<< " " ;
	return (lhs);
}
