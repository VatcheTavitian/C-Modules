#include <iostream>
#include "PhoneBook.hpp"

int main() {
	std::string command;

	std::cout << "COMPILED" << std::endl;
	PhoneBook newPhoneBook;
	std::cout << "Phonebook index is " << newPhoneBook.get_index() << std::endl;

	while (1)
	{
		while (command.length() == 0) {
			std::cout << GREEN << "Welcome to PhoneBook - Enter Command" << COLOR_RESET << std::endl;
			std::cout << "->";
			std::getline(std::cin, command);
		}
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			newPhoneBook.add_contact();
		else if ( command == "SEARCH")
			newPhoneBook.display_contact();
		else
			std::cout << RED << "Command not found - Please select from ADD | SEARCH | EXIT" << COLOR_RESET << std::endl;
		command.clear();
	}
}