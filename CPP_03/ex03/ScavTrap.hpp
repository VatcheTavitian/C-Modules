#ifndef __SCAVTRAP_HPP__
# define __SCAVTRAP_HPP__

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

protected:
	ScavTrap();
	std::string _name;
	int _energyPoints;

public:
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap& toCopy);
	ScavTrap& operator=(const ScavTrap& src);
	~ScavTrap(void);

	virtual void attack(const std::string& target);
	void	guardGate() const;

};

#endif