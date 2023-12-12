#ifndef __AFORM_HPP__
#define __AFORM_HPP__

# include "Bureaucrat.hpp"
# include <ostream>

class Bureaucrat;

class AForm {
	protected:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
		std::string 		_target;
		AForm();
		
	public:
		AForm(const std::string name, int signGrade, int execGrade);
		AForm(const AForm& toCopy);
		virtual AForm& operator=(const AForm& src);
		virtual ~AForm();

		virtual const std::string& 	getName() const;
		virtual bool			getSigned() const;
		virtual int			getSignGrade() const;
		virtual int			getExecGrade() const;
		virtual void		beSigned(Bureaucrat& b);
		void				setTarget(std::string target);
		const std::string&		getTarget() const;
		virtual  void	execute(Bureaucrat const& executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& lhs, const AForm& rhs);

#endif