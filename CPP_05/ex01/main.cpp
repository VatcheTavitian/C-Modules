#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {

	// Test instantiation
	// {
	// 	try {
	// 		Form* form = new Form("brandNewForm", 1, 1);
	// 		std::cout << form->getName() << std::endl;
	// 		std::cout << form->getSigned() << std::endl;
	// 		std::cout << form->getSignGrade() << std::endl;
	// 		std::cout << form->getExecGrade() << std::endl;
	// 		Form *copy = new Form(*form);
	// 		std::cout << copy->getName() << std::endl;
	// 		std::cout << copy->getSigned() << std::endl;
	// 		std::cout << copy->getSignGrade() << std::endl;
	// 		std::cout << copy->getExecGrade() << std::endl;
	// 		std::cout << *form << *copy << std::endl;
	// 		delete form;
	// 		delete copy;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException& e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException& e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }

	//Test signing
	{
		Form* form = new Form("brandNewForm", 10, 10);
		Bureaucrat* tom = new Bureaucrat("Tom", 100);
		tom->signForm(*form);
			
		delete form;
		delete tom;		
	}

	
}