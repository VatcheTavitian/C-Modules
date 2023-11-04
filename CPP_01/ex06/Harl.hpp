#ifndef CPP01__HARL_HPP
#define CPP01__HARL_HPP

# include <iostream>

class Harl {
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	Harl();
	~Harl();
	void	complain(std::string level);
};

#endif