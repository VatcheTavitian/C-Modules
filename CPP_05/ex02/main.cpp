#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {

	Bureaucrat *tim = new Bureaucrat("tim", 137);
	ShrubberyCreationForm *newShrub = new ShrubberyCreationForm("home");
	std::cout << newShrub->getTarget() << '\n' << std::endl;

	tim->signForm(*newShrub);

	try {
	newShrub->execute(*tim);
	} catch (AForm::FormNotSignedException& e) {
		std::cout << e.what() << std::endl;
	} catch (AForm::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
	


	delete newShrub;
	delete tim;


	
}