#include "ScalarConverter.hpp"

#include <string>
#include <cstdlib>

char 		ScalarConverter::_char = 0;
int			ScalarConverter::_int = 0;
float		ScalarConverter::_float = 0;
double		ScalarConverter::_double = 0;

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& toCopy) {
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = toCopy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) {
	if (this == &src)
		return (*this);
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter destructor called" << std::endl;
}


const char* ScalarConverter::ConversionImpossible::what() const throw() {
	return "impossible";
}

int		ScalarConverter::specialCase(const std::string& str) {
	if (str == "nan" || str == "nanf")  {
		char* endptr;
		_double = std::strtod(str.c_str(), &endptr); 
		_float = static_cast<float>(_double); 
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << _float << "f" << std::endl;
		std::cout << "double: " << _double << std::endl;
		return 1;
	}
	else if (str == "inf" || str == "inff" || str == "-inf" || str == "-inff" \
				|| str == "+inf" || str == "+inff")  {
		char* endptr;
		if (str[0] == '-')
			_double = std::strtod("-Infinity", &endptr); 
		else
			_double = std::strtod("Infinity", &endptr); 
		_float = static_cast<float>(_double); 
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << _float << "f" << std::endl;
		std::cout << "double: " << _double << std::endl;
		return 1;
	}
	return (0);
}

int		ScalarConverter::checkIfFloat(const std::string& str) {
	unsigned int i = 0;
	while (str[i]) {
		if (str[i] == '-' || str[i] == '+')
			i++;
		
		if (str[i] && isdigit(str[i])) {
			
			while (str[i] && isdigit(str[i]))
				i++;
			if (str[i] == 'f' && i == str.length() - 1)
				return (1);
			else if (str[i] == '.') {
				i++;
				if (str[i] == 'f' && i == str.length() - 1)
					return (1);
				while (str[i]) {
					if (str[i] && isdigit(str[i])) {
						while (str[i] && isdigit(str[i]))
							i++;
						if (str[i] == 'f' && i == str.length() - 1)
							return (1);
						else
							return (0);
					}
					else
						return (0);
				}
			}
			else
				return (0);
		}
		else
			return (0);
	}
	return (0);
}

int		ScalarConverter::checkIfInt(const std::string& str) {
	unsigned int i = 0;
	if (str[i] == '-')
		i++;
	while (str[i]) {
		if (str[i] && !isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ScalarConverter::checkIfDouble(const std::string& str) {
	unsigned int i = 0;
	unsigned int dp = 0;
	if (str[i] == '-')
		i++;

	while (str[i]) {
		if (str[i] == '.')
			dp++;
		if (str[i] && (!isdigit(str[i]) && str[i] != '.' && str[i] != '+')  && str[i] != 'e') {
			return (0);
		}
		i++;
	}
	if (!dp || dp > 1)
		return (0);
	return (1);
}

int		ScalarConverter::identify(const std::string& str) {
	if (str.length() == 1 && !isdigit(str[0]))
		return (CHAR);
	else if (checkIfInt(str))
		return (INT);
	else if (checkIfFloat(str))
		return (FLOAT);
	else if (checkIfDouble(str))
		return (DOUBLE);
	return (-1);
}

void	ScalarConverter::processChar(const std::string& str) {
	_char = str[0];
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
	if (_int < 32 || _int >= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << _char << "'" << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << _float << ".0f" << std::endl;
	std::cout << "int: " << _double << ".0" << std::endl;
}

int		ScalarConverter::floatHasDecimalPart(const std::string& str) {
	unsigned int i = 0;
	while (str[i]) {
		if (str[i] == '.' || str[i] == 'f') {
			i++;
			break;
		}
		i++;
	}
	if (!str[i] || str[i] == 'f')
		return (1);
	return (0);
}

void	ScalarConverter::processFloat(const std::string& str) {
	_float = atof(str.c_str());
	
	_int = static_cast<int>(_float);
	_double = static_cast<double>(_float);
	if (_int < 32 || _int >= 127)
		std::cout << "char: Non displayable" << std::endl;
	else {
		_char =  static_cast<int>(_int);
		std::cout << "char: '" << _char << "'" << std::endl;
	}
	std::cout << "int: " << _int << std::endl;
	if (floatHasDecimalPart(str))
		std::cout << "float: " << _float << ".0f" << std::endl;
	else
		std::cout << "float: " << _float << "f" << std::endl;
	std::cout << "double: " << _double << std::endl;
}


void	ScalarConverter::processInt(const std::string& str) {
	_int = std::atoi(str.c_str());
	if (_int < 32 || _int >= 127)
		std::cout << "char: non-displayable" << std::endl;
	else {
		_char = static_cast<char>(_int);
		std::cout << "char: '" << _char << "'" << std::endl;
	}
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << _float << ".0f" << std::endl;
	std::cout << "int: " << _double << ".0" << std::endl;
}

void	ScalarConverter::processDouble(const std::string& str) {
	_double = std::stod(str.c_str());
	_int = static_cast<int>(_double);
	if (_int < 32 || _int >= 127)
		std::cout << "char: non-displayable" << std::endl;
	else {
		_char = static_cast<char>(_int);
		std::cout << "char: '" << _char << "'" << std::endl;
	}
	_float = static_cast<float>(_double);
	std::cout << "int: " << _int << std::endl;
	if (floatHasDecimalPart(str))
		std::cout << "float: " << _float << ".0f" << std::endl;
	else
		std::cout << "float: " << _float << "f" << std::endl;
	if (floatHasDecimalPart(str))
		std::cout << "double: " << _double << ".0" << std::endl;
	else
		std::cout << "double: " << _double << std::endl;
}

int		ScalarConverter::outOfRange(const std::string& str) {
	unsigned int i = 0;
	if (str[i] == '-' || str[i] == '+' )
			i++;
	while (str[i])
	{
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'e' && str[i] != '+')
			return (0);
		i++;
	}
	long long int num = atoll(str.c_str());
	long double dm = std::numeric_limits<double>::max();
	long double numdouble = strtod(str.c_str(), NULL);
	if (num > INT_MAX || num < INT_MIN || num > dm || numdouble > dm) {
		std::cout << "OUT OF RANGE"<< std::endl;
		return (1);
	}
	return (0);
}

void ScalarConverter::convert(const std::string& str) {
	if (outOfRange(str))	
		return ;
	if (specialCase(str))
		return ;
	switch (identify(str)) {
		case(CHAR):
			processChar(str);
			break;
		case(INT):
			processInt(str);
			break;
		case(FLOAT):
			processFloat(str);
			break;
		case(DOUBLE):
			processDouble(str);
			break;
		default:
			std::cout << "UNABLE TO CONVERT: " << str << std::endl;
			break;
		
	}
}
