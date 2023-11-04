#include "Zombie.hpp"
Zombie::Zombie()
{

}

Zombie::Zombie(std::string name): _name(name) {
};

void Zombie::announce(void) {
	std::cout << this->_name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->_name << " has been destroyed!" << std::endl;
}

void Zombie::set_name(std::string name) {
	this->_name = name;
}

std::string Zombie::get_name() const {
	return (this->_name);
}