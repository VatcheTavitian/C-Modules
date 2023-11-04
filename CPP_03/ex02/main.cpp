#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void	printInfo(const ClapTrap& src) {
	std::cout << std::endl;
	std::cout << "	Name  = " << src.getName() << std::endl;
	std::cout << "    Hit Points = " << src.getHitPoints() << std::endl;
	std::cout << " Energy Points = " << src.getEnergyPoints() << std::endl;
	std::cout << " Attack Damage = " << src.getAttackDamage() << std::endl;
	std::cout << std::endl;
}

int	main() {

	FragTrap jo = FragTrap("jo");
	FragTrap tom = FragTrap("tom");
	printInfo(tom);


	tom.attack("Jo");
	tom.takeDamage(70);
	tom.beRepaired(10);
	tom.attack("Jo");
	printInfo((tom));

	FragTrap tomCopy = FragTrap(tom);
	printInfo((tomCopy));

	// tomCopy = jo;
	printInfo((tomCopy));
	tomCopy.highFiveGuys();

	return (0);
}