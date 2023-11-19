#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("no name"), _grade(1){
	
}

void	Bureaucrat::setGrade(int grade) {
	this->_grade = grade;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();

}

Bureaucrat::Bureaucrat(std::string name, int grade) :_name(name) {
	setGrade(grade);
	std::cout << "Bureaucrat constructor called" << std::endl;

}


Bureaucrat::Bureaucrat(const Bureaucrat& toCopy) : _name(toCopy._name){
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = toCopy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
	if (this == &src)
		return (*this);
	this->_name = src._name;
	this->_grade = src._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {
		std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string			Bureaucrat::getName() const{
	return (this->_name);
}

int					Bureaucrat::getGrade() const {
	return (this->_grade);
}

const char*	Bureaucrat::GradeTooHighException::what() throw (){
	return "Grade Too High Exception";
}

const char*	Bureaucrat::GradeTooLowException::what() throw() {
	return "Grade Too Low Exception";
}

void				Bureaucrat::increm() {
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;

}
void				Bureaucrat::decrem() {
	if (this->_grade >= 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade++;
}

void				Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	} catch (GradeTooLowException& e) { 
		std::cout << this->getName() << " couldn't sign " << form.getName() 
		<< " because " << e.what() << std::endl;
	}
}


std::ostream& operator<<(std::ostream& lhs, const Bureaucrat& rhs) {
	lhs << rhs.getName() << ", bureaucrat grade " 
		<< rhs.getGrade();
	return lhs;
}