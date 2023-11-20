#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& toCopy);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& src);
		~RobotomyRequestForm();
		
		void	execute(Bureaucrat const& executor) const;
};

#endif