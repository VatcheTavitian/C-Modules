#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main() {
	int	n = 5;
	Zombie *creations;
	creations = zombieHorde( n, "Jo");
	for (int i = 0; i < n; i++)
		creations[i].announce();
	delete[] creations;
	return 0;
}
