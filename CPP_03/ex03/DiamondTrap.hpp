#ifndef __DIAMONDTRAP_HPP__
# define __DIAMONDTRAP_HPP__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string	_name;
	DiamondTrap();

public:
	DiamondTrap(const std::string name);
	DiamondTrap(const DiamondTrap& toCopy);
	DiamondTrap& operator=(const DiamondTrap& src);
	~DiamondTrap(void);

	const std::string	getName(void) const;
	int					getHitPoints(void) const;
	int					getEnergyPoints(void) const;
	int					getAttackDamage(void) const;

	void	setName(std::string name) ;
	void	setHitPoints(int hp) ;
	void	setEnergyPoints(int ep) ;
	void	setAttackDamage(int ad) ;

	void	whoAmI();
	void	printInfo();

};


#endif