#ifndef	CPP01__REPLACE__HPP
#define CPP01__REPLACE__HPP

#include <iostream>
#include <fstream>

class Replace {
	private:
		std::ifstream	_infile;
		std::string		_s1;
		std::string		_s2;
		std::ofstream*	_outfileRef;

	public:
		Replace(void);
		Replace(const std::string& filename, const std::string s1, const std::string s2);
		~Replace(void);
		void			createOutfile(const std::string& filename);
		std::ofstream*	getaccessOutfile(void);
		void			readContents(void);
		void			replaceStrings(void);
};

#endif