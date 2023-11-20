#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		PresidentialPardonForm();

	public:
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& toCopy);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& src);
		~PresidentialPardonForm();
		
		void execute(Bureaucrat const& executor) const;
};

#endif