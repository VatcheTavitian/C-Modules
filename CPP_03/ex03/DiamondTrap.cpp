#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :  ScavTrap (), FragTrap()  {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->_name = "--no name initialized--";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;

}
 

DiamondTrap::DiamondTrap(const std::string name) :  ScavTrap (name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	ClapTrap::_name = name + "_clap_name";
	DiamondTrap::_name = name;
	// ScavTrap::_name = name; // ScavTrap inherits from ClapTrap so name will be _clap_name unless changed
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

void	DiamondTrap::printInfo() {
	std::cout << std::endl;
	std::cout << "	Name  = " << _name << std::endl;
	std::cout << "    Hit Points = " << this->getHitPoints() << std::endl;
	std::cout << " Energy Points = " << this->getEnergyPoints() << std::endl;
	std::cout << " Attack Damage = " << this->getAttackDamage() << std::endl;
	std::cout << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& toCopy) : ClapTrap(toCopy) , ScavTrap(toCopy), FragTrap (toCopy) {

	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = toCopy;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src) {
	std::cout << "DiamondTrap equal operator overload called" << std::endl;
	if (this == &src)
		return (*this);
	ScavTrap::operator=(src);
	FragTrap::operator=(src);
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	return (*this);
}

const std::string	DiamondTrap::getName(void) const {
	return (this->_name);
}

int 	DiamondTrap::getHitPoints(void) const {
			return (this->_hitPoints);
}

int		DiamondTrap::getEnergyPoints(void) const {
			return (this->_energyPoints);
}

int		DiamondTrap::getAttackDamage(void) const {
			return (this->_attackDamage);
}

void	DiamondTrap::setName(std::string name) {
	this->_name = name;
}

void	DiamondTrap::setHitPoints(int hp) {
	this->_hitPoints = hp; 
}

void	DiamondTrap::setEnergyPoints(int ep) {
	this->_energyPoints = ep; 
}

void	DiamondTrap::setAttackDamage(int ad) {
	this->_attackDamage = ad; 
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name is [" << _name << "]" << std::endl;
	std::cout << "ClapTrap name is [" << ClapTrap::_name << "]" << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor called" << std::endl;
}
