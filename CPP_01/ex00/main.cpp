#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main() {
	Zombie zombie("Jack");
	zombie.announce();

	Zombie* zmb_ptr = newZombie("Jill");
	zmb_ptr->announce();

	randomChump("Random Zombie");
	delete zmb_ptr;
	return 0;
}
