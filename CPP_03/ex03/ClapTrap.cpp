#include "ClapTrap.hpp"

ClapTrap::ClapTrap()  {
		_hitPoints = 10;
		_energyPoints = 10;
		_attackDamage = 0;
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& toCopy) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = toCopy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
	std::cout << "ClapTrap equal operator overload called" << std::endl;
	if (this == &src)
		return (*this);
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	if ((this->getHitPoints() <= 0) || (this->getEnergyPoints() <= 0)) {
		std::cout << "ClapTrap does not have enough hit or energy points to attack" << std::endl;
		return ; 
	}

	std::cout << "ClapTrap " << this->getName() << " attacks " << target <<
	" causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->getHitPoints() <= 0) {
		std::cout << "ClapTrap is already dead!" << std::endl;
		return ;
	};

	std::cout << "ClapTrap " << this->getName() << " took a hit of " << amount <<
	" points and now ";
	this->setHitPoints(this->getHitPoints() - amount);

	if (this->getHitPoints() >= 0) 
		std::cout << "has " << this->getHitPoints() << " hit points left " << std::endl;
	else
		std::cout << "has died!!" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount) {
	if ((this->getHitPoints() <= 0) || (this->getEnergyPoints() <= 0)) {
		std::cout << "ClapTrap does not have enough hit or energy points to be repaired" << std::endl;
		return ; 
	}
	this->setHitPoints(this->getHitPoints() + amount);

	std::cout << "ClapTrap " << this->getName() << " repaired itself with " << amount <<
	" points. It now has " << this->getHitPoints() <<  " hit points." << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

const std::string	ClapTrap::getName(void) const {
	return (this->_name);
}

int 	ClapTrap::getHitPoints(void) const {
			return (this->_hitPoints);
}
int		ClapTrap::getEnergyPoints(void) const {
			return (this->_energyPoints);
}
int		ClapTrap::getAttackDamage(void) const {
			return (this->_attackDamage);
}

void	ClapTrap::setName(std::string name) {
	this->_name = name;
}

void	ClapTrap::setHitPoints(int hp) {
	this->_hitPoints = hp; 
}

void	ClapTrap::setEnergyPoints(int ep) {
	this->_energyPoints = ep; 
}

void	ClapTrap::setAttackDamage(int ad) {
	this->_attackDamage = ad; 
}

void	ClapTrap::printInfo() {

	std::cout << std::endl;
	std::cout << "	Name  = " << _name << std::endl;
	std::cout << "    Hit Points = " << _hitPoints << std::endl;
	std::cout << " Energy Points = " << _energyPoints << std::endl;
	std::cout << " Attack Damage = " << _attackDamage << std::endl;
	std::cout << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}