#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main() {

	DiamondTrap jo = DiamondTrap("jo");
	jo.printInfo();
	jo.whoAmI();
	jo.attack("Someone");
	jo.takeDamage(99);
	jo.beRepaired(1);
	jo.printInfo();
	jo.takeDamage(99);
	jo.highFiveGuys();
	return (0);
}