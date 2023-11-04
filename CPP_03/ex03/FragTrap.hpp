#ifndef __FRAGTRAP_HPP__
# define __FRAGTRAP_HPP__

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	
protected:
	FragTrap();

public:
	FragTrap(const std::string name);
	FragTrap(const FragTrap& toCopy);
	FragTrap& operator=(const FragTrap& src);
	~FragTrap(void);

	void	highFiveGuys() const;

};

#endif