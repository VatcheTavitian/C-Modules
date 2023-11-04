#include "Harl.hpp"

int	main(void) {
	Harl harl = Harl();

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	harl.complain("INFO");
	harl.complain("DEBUG");
	return (0);
}