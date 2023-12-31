#ifndef __RPN_HPP__
#define __RPN_HPP__

# include <iostream>
# include <vector>
# include <string>
# include <stack>

class RPN {
	private:
		std::vector<std::string>	_array;
		std::stack<int>	_stack;
		RPN();
		bool 	_isValid(const std::string& formula);
		void	_intoArray(const std::string& formula);
		void	_intoStack(const std::string& formula);
		void	_evaluate(int count, char operation);


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


};

#endif