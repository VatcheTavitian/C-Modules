#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

# include <iostream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& toCopy);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm();
		
		void execute(Bureaucrat const& executor) const;
};

#endif