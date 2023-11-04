#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(const std::string name) : ClapTrap(name){
	std::cout << "FragTrap constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& toCopy) : ClapTrap(toCopy) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = toCopy;
}

FragTrap& FragTrap::operator=(const FragTrap& src) {
	std::cout << "FragTrap equal operator overload called" << std::endl;
	if (this == &src)
		return (*this);
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	return (*this);
}

void	FragTrap::highFiveGuys() const {
	std::cout << "FragTrap " << this->getName() << " gives everyone a high five!" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called" << std::endl;
}