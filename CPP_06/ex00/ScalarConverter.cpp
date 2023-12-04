#include "ScalarConverter.hpp"

#include <string>

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

int		ScalarConverter::identify(const std::string& str) {
	if (str.length() == 1 && !isdigit(str[0]))
		return (CHAR);
	else if (checkIfFloat(str)) {
		return (FLOAT);
	}
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

	// _float = static_cast<float>(_char);
	// std::cout << "int: " << _double << ".0" << std::endl;
}


void	ScalarConverter::processInt(const std::string& str) {
	std::cout <<str;
// 	int		num = std::atoi(str);
// 	// int		sign = 1;
// 	// if (str[0] == '-')
// 	// 	sign = -1;
// 	if (num < 32 || num > 127)
// 		std::cout << "char: non-displayable" << std::endl;
// 	_int = static_cast<int>(_char);
// 	std::cout << "int: " << _int << std::endl;
// 	_float = static_cast<float>(_char);
// 	std::cout << "float: " << _float << ".0f" << std::endl;
// 	_double = static_cast<double>(_char);
// 	std::cout << "int: " << _double << ".0" << std::endl;
}


void ScalarConverter::convert(const std::string& str) {
	if (specialCase(str)) {
		// return printSpecials(str);
		return ;
	}
	switch (identify(str)) {
		case(CHAR):
			processChar(str);
			break;
		case(FLOAT):
			processFloat(str);
			break;
		// case(FLOAT):
		// 	std::cout << "float: " << str << std::endl;
		// 	break;
		// case(DOUBLE):
		// 	std::cout << "double: " << str << std::endl;
		// 	break;
	}
}

// void ScalarConverter::checkChar(const std::string& str) {
// 	std::cout << "std::atoi(str.c_str()): " << std::atoi(str.c_str()) << std::endl;
// 	if (str.length() == 1 && !isdigit(str[0]))
// 		std::cout << "char: " << str << std::endl;
// 	else if (std::atoi(str.c_str()) < 32 && str.length() <= 2)
// 		std::cout << "char: " << "Non displayable" << std::endl;
// 	else if (std::atoi(str.c_str()) >= 32 && std::atoi(str.c_str()) <= 127)
// 		std::cout << "char: " << "'" << static_cast<char>(std::atoi(str.c_str())) << "'" << std::endl;
// 	else if (std::atoi(str.c_str()) >= 128 || std::atoi(str.c_str()) < 0)
// 		throw ScalarConverter::ConversionImpossible();
// 	return ;
// }

// void ScalarConverter::checkInt(const std::string& str) {
// 		std::cout << "int: " << std::atoi(str.c_str()) << std::endl;
// }


// void ScalarConverter::convert(const std::string& str) {
// 	try {
// 		checkChar(str);
// 	} catch (ScalarConverter::ConversionImpossible &e) {
// 		std::cout << "char: " << e.what() << std::endl;
// 	}
// 	try {
// 		checkInt(str);
// 	} catch (ScalarConverter::ConversionImpossible &e) {
// 		std::cout << "int: " << e.what() << std::endl;
// 	}
// 	// try {
// 	// 	checkFloat(str);
// 	// } catch (ScalarConverter::ConversionImpossible &e) {
// 	// 	std::cout << "float: " << e.what() << std::endl;
// 	// }

	// switch (getType(str)) {
	// 	case(CHAR):
	// 		std::cout << "char: " << str << std::endl;
	// 		break;
	// 	case(INT):
	// 		std::cout << "int: " << str << std::endl;
	// 		break;
	// 	case(FLOAT):
	// 		std::cout << "float: " << str << std::endl;
	// 		break;
	// 	case(DOUBLE):
	// 		std::cout << "double: " << str << std::endl;
	// 		break;

// 	// }
// }