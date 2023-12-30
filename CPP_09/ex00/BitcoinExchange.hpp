#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <string>
#include <ctime>
#include <sstream>
#include <climits>
#include <locale.h>
#include <cmath>

class BitcoinExchange {
	private:
		std::map<std::string, double>	_data;
		void	_createDatabase();
		void	_createInput(std::string filename);
		void	_deepCopy(const BitcoinExchange& src);
		bool	_isValidDate(std::string& dateString);
		double	_findClosest(std::string& dateString);
		bool	_valueHasDigits(std::string& value);

	public:
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& toCopy);
		BitcoinExchange& operator=(const BitcoinExchange& src);
};

#endif