#include "Bureaucrat.hpp"

int	main() {

	// Test instantiation
	{
		std::string tomName = "Tom";
		Bureaucrat* tom;
		try {
			tom = new Bureaucrat(tomName, 149);
			std::cout << *tom << std::endl;
			delete tom;
		}
		catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		}
	}

	// Test decrement
	{
		std::string tomName = "Tom";
		Bureaucrat* tom;
		tom = new Bureaucrat(tomName, 149);
		std::cout << *tom << std::endl;
		try {
			tom->decrem();
			tom->decrem();
			std::cout << *tom << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		}
		delete tom;
	}
	// Test increment
	{
		std::string tomName = "Tom";
		Bureaucrat* tom;
		tom = new Bureaucrat(tomName, 2);
		std::cout << *tom << std::endl;
		try {
			tom->increm();
			tom->increm();
			std::cout << *tom << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		}
		delete tom;
	}
}