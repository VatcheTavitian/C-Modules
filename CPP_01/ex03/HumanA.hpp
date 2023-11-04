#ifndef CPP01__HUMANA__HPP
#define CPP01__HUMANA__HPP

# include <iostream>
# include "Weapon.hpp"

class	HumanA {
private:
	std::string	_humanname;
	Weapon		&weaponA;

public:
	HumanA();
	HumanA(const std::string name, Weapon& newWeapon);
	~HumanA();
	void	attack(void);

};

#endif