#ifndef CPP01_ZOMBIE_HPP
#define CPP01_ZOMBIE_HPP
#include <iostream>

class Zombie {
private:
	std::string	_name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void 		announce(void);
	void 		set_name(std::string name);
	std::string get_name() const;
};

#endif //CPP01_ZOMBIE_HPP
