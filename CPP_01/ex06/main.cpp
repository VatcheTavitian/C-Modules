#include "Harl.hpp"

int	main(int argc, char **argv) {

	if (argc != 2)
	{
		std::cout << "You need to input a complaint level!" << std::endl;
		return (1);
	}
	Harl harl = Harl();
	harl.complain(argv[1]);

	return (0);
}