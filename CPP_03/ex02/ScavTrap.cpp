#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name){
	std::cout << "ScavTrap constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& toCopy) : ClapTrap(toCopy) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = toCopy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
	std::cout << "ScavTrap equal operator overload called" << std::endl;
	if (this == &src)
		return (*this);
	ClapTrap::operator=(src);
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	return (*this);

}

void	ScavTrap::guardGate() const {
	std::cout << "ScavTrap " << this->getName() << " is in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called" << std::endl;
}