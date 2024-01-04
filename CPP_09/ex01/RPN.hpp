#ifndef __RPN_HPP__
#define __RPN_HPP__

# include <iostream>
# include <vector>
# include <string>
# include <stack>

class RPN {
	private:
		std::stack<int>	_stack;
		RPN();
		bool 	_isValid(const std::string& formula);
		bool 	_operatorsValid(const std::string& formula);
		void	_intoStack(const std::string& formula);
		void	_evaluate(char operation);

		enum oper {
			ADD,
			SUBTRACT,
			MULTIPLY,
			DIVIDE,
		};

	public:
		RPN(const std::string& formula);
		~RPN();
		RPN(const RPN& toCopy);
		RPN& operator=(const RPN& src);

	class InvalidSyntax: public std::exception {
		public:
				virtual const char* what() const throw();
	};
};

#endif