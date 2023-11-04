#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_name = "--no name initialized--";
	this->_hitPoints = 10;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}
 

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name){
	std::cout << "ScavTrap constructor called" << std::endl;
	this->_hitPoints = 10;
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
 
void ScavTrap::attack(const std::string& target) {
	if ((this->getHitPoints() <= 0) || (this->getEnergyPoints() <= 0)) {
		std::cout << "ScavTrap does not have enough hit or energy points to attack" << std::endl;
		return ; 
	}

	std::cout << "ScavTrap " << _name << " attacks " << target <<
	" causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	ScavTrap::guardGate() const {
	std::cout << "ScavTrap " << this->getName() << " is in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called" << std::endl;
}