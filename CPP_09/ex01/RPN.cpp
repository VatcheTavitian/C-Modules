#include "RPN.hpp"

RPN::RPN() {
	std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN(const std::string& formula) {
	std::cout << "RPN constructor called" << std::endl;
	if (!this->_isValid(formula))
		std::cout << "Error: formula contains illegal characters or is invalid" << std::endl;
	// this->_intoArray(formula);
	this->_intoStack(formula);
	//print
	// for (std::vector<std::string>::iterator it = this->_array.begin(); it != this->_array.end(); ++it) {
    //     std::cout << *it << "\n";
    // }


}

RPN::~RPN() {
	std::cout << "RPN destructor called" << std::endl;
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
	i = 0;
	while (formula[i]) {
		if ((formula[i] == '/' || formula[i] == '*'))
		{
			if (formula[i + 1] != ' ')
				return (false);
			if (i + 2 <= static_cast<int>(formula.length())) {
				if (formula[i + 2] == '*' || formula[i + 2] == '/')
					return (false);
			}
		}
		i++;	
	}
	return (true);
}

void	RPN::_intoArray(const std::string& formula) {
	int i = 0;
	int j = 0;
	std::string temp;

	while (i < static_cast<int>(formula.length())) {
		if (formula[i] == ' ') {
			while (formula[i] == ' ')
			 	i++;
			j = i;
		}
		else if (isdigit(formula[i])) {
			while (isdigit(formula[i]))
				i++;
			temp = formula.substr(j, i - j);
			this->_array.insert(this->_array.begin(), temp);
			i++;
			j = i;
		}
		else if (formula[i] == '+' || formula[i] == '-'
			|| formula[i] == '/' || formula[i] == '*') {
				i++;
				temp = formula.substr(j, i - j );
				this->_array.insert(this->_array.begin(), temp);
				j = i;
			}
	}
}

	void	RPN::_intoStack(const std::string& formula) {
		int i = 0;
		int count = 0;
		std::string ops = "+-*/";
		while (i < static_cast<int>(formula.length())) {
			if (formula[i] == ' ')
				i++;
			if (isdigit(formula[i])) {
				int num = 0;
				while (isdigit(formula[i])) {
					num = num * 10 + (formula[i] - '0');
					i++;
				}
				// std::cout << "ADDED NUM: " << num <<std::endl;
				this->_stack.push(num);
				count++;
			}
			else if (formula[i] == '+' || formula[i] == '-'
					|| formula[i] == '*' || formula[i] == '/') {
				this->_evaluate(count, formula[i]);
				i++;
				count = 0;
				// std::cout << "again = " << i << std::endl;
			}
			i++;
		}
		std::cout << "RESULT = " << _stack.top() << "- stack length = " << _stack.size();
	}

	void	RPN::_evaluate(int count, char operation) {
		int doOp;
		int num1 = 0;
		int num2 = 0;
		int result = 0;

		if (operation == '+')
			doOp = ADD;
		else if (operation == '-')
			doOp = SUBTRACT;
		else if (operation == '*')
			doOp = MULTIPLY;
		else if (operation == '/')
			doOp = DIVIDE;

		if (count == 1) {
			num1 = this->_stack.top();
			this->_stack.pop();
			num2 = this->_stack.top();
		}
		else if (count == 2) {
			num1 = this->_stack.top();
			this->_stack.pop();
			num2 = this->_stack.top();
			this->_stack.pop();
		}
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
				result = num1 / num2;
				break;
		}
		// std::cout << "NUM1 IS " << num1 << std::endl;
		// std::cout << "NUM2 IS " << num2 << std::endl;
		// std::cout << "RESULT HERE IS " << result << std::endl;
		if (count == 2)
			this->_stack.push(result);
		else {
			this->_stack.pop();
			this->_stack.push(result);
		}
			

		// std::cout << "found " << count << operation << std::endl;
	}