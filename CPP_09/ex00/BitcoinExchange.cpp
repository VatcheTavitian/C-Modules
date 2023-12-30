#include "BitcoinExchange.hpp"

	BitcoinExchange::BitcoinExchange() {
		// std::cout << "BitcoinExchange default constructor called" << std::endl;
	}

	BitcoinExchange::BitcoinExchange(std::string filename) {
		// std::cout << "BitcoinExchange constructor called" << std::endl;
		_createDatabase();
		_createInput(filename);
	}

	BitcoinExchange::~BitcoinExchange() {
		// std::cout << "BitcoinExchange destructor called" << std::endl;
	}

	BitcoinExchange::BitcoinExchange(const BitcoinExchange& toCopy)  {
		*this = toCopy;
		std::cout << "BitcoinExchange copy constructor called" << std::endl;
	}

	BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
		std::cout << "BitcoinExchange assignment operator called" << std::endl;
		if (this == &src)
			return *this;
		this->_deepCopy(src);
		return *this;
	}

	void	BitcoinExchange::_createDatabase() {
		std::ifstream data;
		std::string line;
		// bool isDecimal = false;
		// int count = 0;

		data.open("data.csv");
		if (!data.is_open()) {
			std::cout << "Unable to open input file" << std::endl;
		}
		while (std::getline(data, line)) {
			std::string key = line.substr(0, line.find(","));
			const std::string value = line.substr(line.find(",") + 1, line.length());
			double dValue = strtod(value.c_str(), NULL);
			this->_data[key] = dValue;

			// NOTE!! stod loses precision in conversion eg 47115.93 becomes 47115.9
			// I tried to manually convert string to double below, but when adding decimal values, dValue rounds up.
			// Seems to be a restriction in the architecture...

			// double dValue = 0;
			// int i = 0;
			// while (value[i]) {
					
			// 	if (!isDecimal && value[i] != '.') 				
			// 		dValue = dValue * 10 + (static_cast<int>(value[i]) - 48);
			// 	else if (isDecimal) {
			// 		std::cout << "  LOOKING AT " << value[i]  << " result = " << ((static_cast<int>(value[i]) - 48) / std::pow(10.0, count))<< std::endl;
			// 		dValue = dValue + ((static_cast<int>(value[i]) - 48) / std::pow(10.0, count));
			// 		count++;
			// 	}
			// 	if (value[i] == '.') {
			// 		isDecimal = true;
			// 		count++;
			// 	}
			// 	i++;
			// }
			// std::cout << "value = " << value << std::endl;
			// std::cout << "dVALUe = " << dValue << std::endl;
		}
	}

	bool	BitcoinExchange::_isValidDate(std::string& dateString) {
		std::tm tmStruct = {};
	
		std::istringstream dateStream(dateString);
		std::sscanf(dateString.c_str(), "%d-%d-%d", &tmStruct.tm_year, &tmStruct.tm_mon, &tmStruct.tm_mday);
	
		std::time_t currentTime;
    	std::time(&currentTime);
    	std::tm* today = std::localtime(&currentTime);

		if (tmStruct.tm_year == (today->tm_year +1900 ) && (tmStruct.tm_mon > today->tm_mon) && (tmStruct.tm_mday > today->tm_mday))
			return false;
		if (tmStruct.tm_year > (today->tm_year +1900 ) || tmStruct.tm_year < 2009)
			return false;
		if (tmStruct.tm_mon < 1 || tmStruct.tm_mon > 12)
			return (false);
		if (tmStruct.tm_mday < 1 || tmStruct.tm_mday > 31)
			return (false);
		return (true);
	}

	double	BitcoinExchange::_findClosest(std::string& dateString) {
		int diffInDays;
		std::tm tmStruct = {};
		std::sscanf(dateString.c_str(), "%d-%d-%d", &tmStruct.tm_year, &tmStruct.tm_mon, &tmStruct.tm_mday);
		std::string prevKey;

		for (std::map<std::string, double>::const_iterator it = _data.begin(); it != _data.end(); ++it) {
			std::tm tmStructKey = {};
			std::sscanf(it->first.c_str(), "%d-%d-%d", &tmStructKey.tm_year, &tmStructKey.tm_mon, &tmStructKey.tm_mday);
			std::time_t time1 = std::mktime(const_cast<std::tm*>(&tmStruct));
        	std::time_t time2 = std::mktime(const_cast<std::tm*>(&tmStructKey));
			
			diffInDays = static_cast<int>((time2 - time1) / (60 * 60 * 24));
			if (diffInDays > 0)
				return (this->_data[prevKey]);
			if (it->first != "date")
				prevKey = it->first;
    	}

		return this->_data[prevKey] ;
	}

	bool	BitcoinExchange::_valueHasDigits(std::string& value) {
		int i = 0;
		if (value[i] == ' ') {
			while (value[i] == ' ')
			 	i++;
			if (!value[i])
				return (false);
		}
		while (value[i]) {
			if (!std::isdigit(value[i]) && value[i] != '.' && value[i] != 'f' && value[i] != '-') {
				return (false);
			}
			i++;
		}
		return (true);
	}

	void	BitcoinExchange::_createInput(std::string filename) {
		std::ifstream file;
		std::string line;


		file.open(filename.c_str());
		if (!file.is_open()) {
			std::cout << "Unable to open input file" << std::endl;
		}
		std::getline(file, line);
		while (std::getline(file, line)) {
			std::string key = line.substr(0, line.find("|") - 1);
			std::string value = line.substr(line.find("|") + 1, line.length());
			double dValue = strtod(value.c_str(), NULL);

			if (!_valueHasDigits(value))
				std::cout << "Error: missing valid value" << std::endl;
			else if (std::atol(value.c_str()) > INT_MAX)
				std::cout << "Error: too large a number." << std::endl;
			else if (_isValidDate(key) && std::atoi(value.c_str()) >= 0) {
				if (this->_data.find(key) != this->_data.end())
					std::cout << key << " =>" << value << " = " << dValue *  this->_data[key] << std::endl;
				else 
					std::cout << key << " =>" << value << " = " << dValue * _findClosest(key) << std::endl;
			}
			else if (!_isValidDate(key))
				std::cout << "Error: bad input => " << key << std::endl;
			else if (std::atoi(value.c_str()) < 0)
				std::cout << "Error: not a positive number." << std::endl;
		}
	}

	void	BitcoinExchange::_deepCopy(const BitcoinExchange& src) {
		for (std::map<std::string, double>::const_iterator it = src._data.begin(); it != src._data.end(); it++)
			this->_data[it->first] = it->second;
	}