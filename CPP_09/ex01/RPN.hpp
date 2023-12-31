#ifndef __RPN_HPP__
#define __RPN_HPP__

# include <iostream>
# include <vector>
# include <string>

class RPN {
	private:
		std::vector<std::string>	_array;
		RPN();
		bool 	_isValid(const std::string& formula);
		void	_intoArray(const std::string& formula);

	public:
		RPN(const std::string& formula);
		~RPN();
		RPN(const RPN& toCopy);
		RPN& operator=(const RPN& src);


};

#endif