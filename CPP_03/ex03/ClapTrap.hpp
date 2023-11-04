#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

# include <iostream>

class ClapTrap {
protected:
	std::string	_name;
	int			_hitPoints;  // constructor sets to 10
	int			_energyPoints; // constructor sets to 10
	int			_attackDamage; // // constructor sets to 0
	ClapTrap(void);

public:
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap& toCopy);
	ClapTrap& operator=(const ClapTrap& src);
	~ClapTrap(void);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	const std::string	getName(void) const;
	int					getHitPoints(void) const;
	int					getEnergyPoints(void) const;
	int					getAttackDamage(void) const;

	void	setName(std::string name) ;
	void	setHitPoints(int hp) ;
	void	setEnergyPoints(int ep) ;
	void	setAttackDamage(int ad) ;
	virtual void	printInfo(const ClapTrap& src);
};


#endif