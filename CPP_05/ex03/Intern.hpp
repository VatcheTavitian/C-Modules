#ifndef __INTERN_HPP__
#define __INTERN_HPP__

# include <iostream>
# include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& toCopy);
		Intern& operator=(const Intern& src);
		~Intern();

		AForm* makeForm(const std::string&name, const std::string& target);

		class FormDoesNotExist : public std::exception {
			public:
				const char* what() throw();
		};
};

#endif