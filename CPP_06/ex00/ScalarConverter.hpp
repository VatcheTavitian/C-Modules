#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

# include <iostream>
# include <exception>
# include <cstdlib>
# include <string>
# include <limits>

class ScalarConverter {
	private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& toCopy);
	ScalarConverter& operator=(const ScalarConverter& src);

	static char 	_char;
	static int		_int;
	static float 	_float;
	static double	_double;

	enum input_type {
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		SPECIAL,
		OUTOFRANGE
	};


	static int		identify(const std::string& str);
	static int		checkIfInt(const std::string& str);
	static int		checkIfFloat(const std::string& str);
	static int		checkIfDouble(const std::string& str);
	static int		floatHasDecimalPart(const std::string& str);
	static int		outOfRange(const std::string& str);
	static int		specialCase(const std::string& str);
	static void		processChar(const std::string& str);
	static void		processInt(const std::string& str);
	static void		processFloat(const std::string& str);
	static void		processDouble(const std::string& str);


	public:
		static void convert(const std::string& str);

	class ConversionImpossible: public std::exception {
		public:
			virtual const char* what() const throw(); 
	};
};


#endif