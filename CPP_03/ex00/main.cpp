#include "ClapTrap.hpp"

void	printInfo(const ClapTrap& src) {
	std::cout << std::endl;
	std::cout << "ClapTrap Name  = " << src.getName() << std::endl;
	std::cout << "    Hit Points = " << src.getHitPoints() << std::endl;
	std::cout << " Energy Points = " << src.getEnergyPoints() << std::endl;
	std::cout << " Attack Damage = " << src.getAttackDamage() << std::endl;
	std::cout << std::endl;
}

int	main() {

	ClapTrap jo = ClapTrap("Jo");
	ClapTrap jack = ClapTrap(jo);
	printInfo((jo));
	// printInfo((jack));

	jo.attack("Tom");
	jo.takeDamage(5);
	jo.beRepaired(1);
	printInfo((jo));

	jo.attack("Andrew");
	jo.takeDamage(10);
	printInfo((jo));

	jo.attack("Tom");
	jo.beRepaired(10);
	return (0);
}