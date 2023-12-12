#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main() {

	Intern *intern = new Intern();
	try {

	AForm* newForm = intern->makeForm("ShrubberyCreationForm", "Home");
	// AForm* newForm = intern->makeForm("RobotomyRequestForm", "Robot");
	// AForm* newForm = intern->makeForm("PresedentialPardonForm", "Random person");
	// AForm* newForm = intern->makeForm("NONEXISTENTFORM", "Home");
	delete newForm;
	} catch (Intern::FormDoesNotExist& e) {
		std::cout << e.what() << std::endl;
	}
	delete intern;
	
}