#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {

	// Test ShrubberyCreationForm
	{
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
	


	// delete newShrub;
	// delete tim;
	// }

	// // Test RobotomyRequestForm
	// {
	// 	Bureaucrat *tim = new Bureaucrat("tim", 45);
	// 	RobotomyRequestForm *robot = new RobotomyRequestForm("A robot");

	// 	tim->signForm(*robot);
	// 	try {
	// 		robot->execute(*tim);
	// 		robot->execute(*tim);
	// 		robot->execute(*tim);
	// 		robot->execute(*tim);
	// 	} catch (AForm::FormNotSignedException& e) {
	// 		std::cout << e.what() << std::endl;
	// 	} catch (AForm::GradeTooLowException& e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// 	delete tim;
	// 	delete robot;
	// }

	// Test Presedential Pardon
	// 	{
	// 	Bureaucrat *tim = new Bureaucrat("Tim", 72);
	// 	Bureaucrat *jim = new Bureaucrat("Jim", 45);
	// 	PresidentialPardonForm *pardon = new PresidentialPardonForm("Pardon");
	// 	// PresidentialPardonForm *pardonCopy = new PresidentialPardonForm(*pardon);
	// 	// std::cout << pardonCopy->getExecGrade() << std::endl;
	// 	try {
	// 		tim->signForm(*pardon);
	// 		pardon->execute(*tim);
	// 		jim->executeForm(*pardon);
			
	// 	} catch (AForm::FormNotSignedException& e) {
	// 		std::cout << e.what() << std::endl;
	// 	} catch (AForm::GradeTooLowException& e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// 	delete tim;
	// 	delete jim;
	// 	delete pardon;
	// 	// delete pardonCopy;
	// }

}