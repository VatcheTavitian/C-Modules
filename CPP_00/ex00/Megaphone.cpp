#include <iostream>

void	printMessage(const std::string& msg)
{
	for (unsigned int i = 0; i < msg.length(); i++)
		std::cout << char(toupper(msg[i]));
}

int main(int argc, char **argv)
{
	if (argc == 1)
		printMessage("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
	else {
		for (int i = 1; i < argc; i++)
			printMessage(argv[i]);
	}
	std::cout << std::endl;
}


