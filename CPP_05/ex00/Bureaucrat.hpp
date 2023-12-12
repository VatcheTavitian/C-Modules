#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

# include <iostream>

class Bureaucrat {
	private:
		Bureaucrat();	
		const std::string		_name;
		int				_grade;
	public:

		Bureaucrat(std::string& name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& toCopy);
		Bureaucrat& operator=(const Bureaucrat& src);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		std::string			getName() const;
		int					getGrade() const;
		void				setGrade(int grade);
		void				increm();
		void				decrem();
};

std::ostream& operator<<(std::ostream& lhs, const Bureaucrat& rhs);

#endif
