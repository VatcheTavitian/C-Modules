#ifndef __FORM_HPP__
#define __FORM_HPP__

# include "Bureaucrat.hpp"
# include <ostream>

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
		Form();
		
	public:
		Form(const std::string name, int signGrade, int execGrade);
		Form(const Form& toCopy);
		Form& operator=(const Form& src);
		~Form();

		const std::string& 	getName() const;
		bool				getSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		void		beSigned(Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& lhs, const Form& rhs);

#endif