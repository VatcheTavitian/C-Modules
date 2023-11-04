#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap& toCopy);
	ScavTrap& operator=(const ScavTrap& src);
	~ScavTrap(void);

	void	guardGate() const;

};
#endif