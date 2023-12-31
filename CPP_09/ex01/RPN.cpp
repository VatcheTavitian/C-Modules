#include "RPN.hpp"

RPN::RPN() {
	std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN(const std::string& formula) {
	std::cout << "RPN constructor called" << std::endl;
	if (!this->_isValid(formula))
		std::cout << "Error: formula contains illegal characters or is invalid" << std::endl;
	this->_intoArray(formula);

	//print
	for (std::vector<std::string>::iterator it = this->_array.begin(); it != this->_array.end(); ++it) {
        std::cout << *it << "\n";
    }


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
