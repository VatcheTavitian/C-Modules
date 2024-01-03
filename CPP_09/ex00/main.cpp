#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: could not open file" << std::endl;
		return -1;
	}
	BitcoinExchange* btc = new BitcoinExchange(argv[1]);
	delete btc;

	// test copy constructor for deep copy
	// set private to public in class definition
	// {
	// BitcoinExchange btcCOPY = BitcoinExchange(*btc);

	// for (std::map<std::string, double>::const_iterator it = btcCOPY._data.begin(); it != btcCOPY._data.end(); it++)
	// 		std::cout << it->first << " | " << it->second << std::endl;

	// delete btcCOPY;
	// }
}