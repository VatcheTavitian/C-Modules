#ifndef CPP01_ZOMBIE_HPP
#define CPP01_ZOMBIE_HPP
#include <iostream>

class Zombie {
private:
	std::string	_name;

public:
	Zombie(std::string name);
	~Zombie();
	void announce( void );
};

#endif //CPP01_ZOMBIE_HPP
