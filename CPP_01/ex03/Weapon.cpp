#include "Weapon.hpp"

Weapon::Weapon(const std::string type): _type(type){
	std::cout << "Weapon " << this->_type << " created!" << std::endl;;
};

const std::string& Weapon::getType()  {
	return (this->_type);
};

void	 Weapon::setType(const std::string type) {
	this->_type = type;
};

Weapon::~Weapon() {
	std::cout << "Weapon " << this->_type << " destroyed!" << std::endl;
};