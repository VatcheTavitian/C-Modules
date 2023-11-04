#include "HumanB.hpp"

HumanB::HumanB() :  _humanname("noname"), weaponB(NULL) {
	return ;
};

HumanB::HumanB(const std::string name): _humanname(name),  weaponB(NULL) {
	return ;
};

void	HumanB::attack(void) {
	std::cout << this->_humanname << " attacks with their " << this->weaponB->getType() << std::endl;
};

void	HumanB::setWeapon(Weapon &weapon) {
	this->weaponB = &weapon ;
}

HumanB::~HumanB() {
	std::cout << this->_humanname << " destroyed..." << std::endl;
}

