#ifndef CPP01__HUMANB__HPP
#define CPP01__HUMANB__HPP

# include <iostream>
# include "Weapon.hpp"

class	HumanB {
private:
	std::string	_humanname;
	Weapon		*weaponB;

public:
	HumanB();
	HumanB(const std::string name);
	~HumanB();
	void	attack(void);
	void	setWeapon(Weapon &weapon);

};

#endif