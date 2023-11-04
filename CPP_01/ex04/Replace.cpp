#include "Replace.hpp"

Replace::Replace(const std::string& filename, const std::string s1, const std::string s2) : \
	 _infile(filename), _s1(s1), _s2(s2), _outfileRef(NULL) {
	if (!_infile){
		std::cout << "Failed to open file" << std::endl;
		exit(1);
	}
	if (!s1.length()){
		std::cout << "Search string cannot be empty" << std::endl;
		exit(1);
	}
	else
		std::cout << "Object of replace class successfuly initialised" << std::endl;
}	

void	Replace::createOutfile(const std::string& filename) {
	std::string filenameMod = filename + ".replace";
	this->_outfileRef = new std::ofstream(filenameMod);
	std::cout << "File '" << filenameMod << "' created." << std::endl;
}

void	Replace::readContents(void) {
	if (!(this->_outfileRef))
		std::cout <<  "Set output file before proceeding" << std::endl;
	std::string temp;
	std::string	line;
	std::string	replacement;

	while (getline(this->_infile, temp))
	{
		line = temp;
		size_t pos = 0; 
		size_t found;
		while ((found = line.find(this->_s1, pos)) != std::string::npos)
		{
			replacement += line.substr(pos, found - pos);
			replacement += this->_s2;
			pos = found + this->_s1.length();
		}
		replacement += line.substr(pos);
		if (this->_infile.eof())
			*(this->_outfileRef) << replacement;
		else
			*(this->_outfileRef) << replacement << std::endl;
		replacement.clear();
		}
	}

std::ofstream*	Replace::getaccessOutfile(void) {
	return (this->_outfileRef);
}

Replace::~Replace(void) {
	if (this->_outfileRef)
		delete this->_outfileRef;
	std::cout << "Replace object destroyed" << std::endl;
}