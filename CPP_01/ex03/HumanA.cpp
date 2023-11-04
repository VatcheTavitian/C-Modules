#include "HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon& newWeapon): _humanname(name), weaponA(newWeapon) {
	return ;
};

void	HumanA::attack(void) {
	std::cout << this->_humanname << " attacks with their " << this->weaponA.getType() << std::endl;
};

HumanA::~HumanA() {
	std::cout << this->_humanname << " destroyed..." << std::endl;
}

