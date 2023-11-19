#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery", 145, 137) {
	this->_target = target;
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& toCopy) :AForm(toCopy) {
	*this = toCopy;
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	std::cout << "ShrubberyCreationForm equal operator called" << std::endl;
	if (this == &src)
		return (*this);
	AForm::operator=(src);
	this->_target = src._target;
	return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) {
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_execGrade)
		throw AForm::GradeTooLowException();
	std::ofstream outfile((this->getTarget() + "_shrubbery").c_str());
	outfile << 
	"KKKXXXXXXXKKKXXXXXXXXKXXXXXXXXXKKXXXXXXXXXXXXXXXKK\n"
	"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXK\n"
	"XXXXXXXXXXXXXXXXXXX0O00kxxxkOO00KXXXXXXXXXXXXXXXXX\n"
	"XXXXXXXXXXXXXXKOkkdolclc,,,,;:coxOXNXXXXXXXXXXXXXX\n"
	"XXXXXXXXXXNXK0kolc::c:;;;::;;::;;lOXNXXXXXXXXXXXXX\n"
	"NNNNNNNXXXKOdllll:;c:::::;;,'''..'ckXNXXNNNNNNNNXX\n"
	"XNNNNNX0xxoc::cc::::;,,,;;::;,','..'cONNNNNNNNNNNN\n"
	"NNNNNNKkl:;::;cl:cc;;;;:ccllcc:,'....:dOXNNNNNNNNN\n"
	"NNNX0Oxlll:cc::ccoooolcclooc:lc,''''...;o0XNNNNNNN\n"
	"NNN0dll:cccc:;,;,;::clll:;;,';;,',;,',,,cloONNNNNN\n"
	"NNNOolc,;locccccc;''';cl:,,,,;,',,,,,,;:::;;dXNNNN\n"
	"0KK0xl:::clc;;cll:,;,';::,;;;,''',,,,;;'''',:xkkxx\n"
	"',cc;:cccccc,;:::;;;'':lllc:,',;'.,,.........';::c\n"
	".',;:clccllc:c:,,;;'',:;''',,',,'.....';;;;:codddx\n"
	"llooodddddxxxxddddoolod;.,cxddxdddddxxkkkkkOkkkkkk\n"
	"dddddxxxxxkkkxxxxxxxxxxc,,lkkkxxxdddxddodxxxxkOOkk\n"
	"xxxxxkkxddxkkxxdooolllllodxkkOkxxdoodddoxkkkkk0K0k\n"
	<< std::endl;
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}



// const std::string& 	ShrubberyCreationForm::getName() const {
// 	return (this->_name);
// }
// bool				ShrubberyCreationForm::getSigned() const {
// 	return (this->_signed);
// }

// int			ShrubberyCreationForm::getSignGrade() const {
// 	return (this->_signGrade);
// }

// int			ShrubberyCreationForm::getExecGrade() const {
// 	return (this->_execGrade);
// }

// void		ShrubberyCreationForm::beSigned(Bureaucrat& b) {
// 	if (this->getSignGrade() < b.getGrade())
// 		throw Bureaucrat::GradeTooLowException();
// 	else if (!this->_signed) {
// 		this->_signed = true;
// 	} else {
// 		std::cout << "AForm has already been signed" << std::endl;
// 	}
// }