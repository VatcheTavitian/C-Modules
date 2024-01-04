#include "RPN.hpp"

RPN::RPN() {
	// std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN(const std::string& formula) {
	// std::cout << "RPN constructor called" << std::endl;
	if (!this->_isValid(formula)) // || !this->_operatorsValid(formula))
		throw RPN::InvalidSyntax();
	this->_intoStack(formula);
	if (this->_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else
		throw RPN::InvalidSyntax();
}

RPN::~RPN() {
	// std::cout << "RPN destructor called" << std::endl;
}

RPN::RPN(const RPN& toCopy) {
	std::cout << "RPN copy constructor called" << std::endl;
	*this = toCopy;
}

RPN& RPN::operator=(const RPN& src) {
	std::cout << "RPN assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

bool RPN::_isValid(const std::string& formula) {
	int i = 0;

	if (formula.length() == 0)
		return (false);
	while (formula[i]) {
		if (formula[i] != ' ')
			break ;
		else
			i++;
	}
	if (i == static_cast<int>(formula.length()))
		return (false);
	
	i = 0;
	while (formula[i]) {
		if (!isdigit(formula[i]) && formula[i] != '+' && formula[i] != '-'
			&& formula[i] != '/' && formula[i] != '*' && formula[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool RPN::_operatorsValid(const std::string& formula) {
	int i = 0;

	while (i < static_cast<int>(formula.length())) {
		if (formula[i] == '+' || formula[i] == '-' || formula[i] == '*' || formula[i] == '/') {
			if ((i + 2 < static_cast<int>(formula.length())) &&
				(formula[i + 2] == '+' || formula[i + 2] == '-' || formula[i + 2] == '*' || formula[i + 2] == '/'))
				return (false);
		}
		i++;
	}
	return (true);
}

	void	RPN::_intoStack(const std::string& formula) {
		int i = 0;
	
		while (i < static_cast<int>(formula.length())) {
			if (formula[i] == ' ')
				i++;
			if (isdigit(formula[i])) {
				int num = 0;
				while (isdigit(formula[i])) {
					num = num * 10 + (formula[i] - '0');
					i++;
				}
				this->_stack.push(num);
			}
			else if (formula[i] == '+' || formula[i] == '-'
					|| formula[i] == '*' || formula[i] == '/') {
				this->_evaluate(formula[i]);
				i++;
			}
			else
				i++;
		}
		
	}

	void	RPN::_evaluate(char operation) {
		int doOp = 0, num1 = 0, num2 = 0, result = 0;
	
		if (operation == '+')
			doOp = ADD;
		else if (operation == '-')
			doOp = SUBTRACT;
		else if (operation == '*')
			doOp = MULTIPLY;
		else if (operation == '/')
			doOp = DIVIDE;

		if (this->_stack.size() >= 2) {
			num1 = this->_stack.top();
			this->_stack.pop();
			num2 = this->_stack.top();
			this->_stack.pop();
			switch (doOp){
			case (0):
				result = num1 + num2;
				break;
			case (1):
				result = num2 - num1;
				break;
			case (2):
				result = num1 * num2;
				break;
			case (3):
				if (num1 == 0)
					throw RPN::InvalidSyntax();
				result = num2 / num1;
				break;
			}
			this->_stack.push(result);
		}
		else	
			throw RPN::InvalidSyntax();

	}

	const char* RPN::InvalidSyntax::what() const throw() {
		return "Error: invalid syntax";
	}