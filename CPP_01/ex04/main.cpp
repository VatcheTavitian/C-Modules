#include "Replace.hpp"

int	main(int argc, char**argv) {
	if (argc != 4) {
		std::cout << "Insufficient arguments" << std::endl;
		return (1);
	}
	Replace *newFile = new Replace(argv[1], argv[2], argv[3]);
	newFile->createOutfile(argv[1]);
	newFile->readContents();
	delete newFile;
}
