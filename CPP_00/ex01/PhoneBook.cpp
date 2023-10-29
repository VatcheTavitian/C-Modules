#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook(void){
	Contact contacts[8];
	this->phoneBookSize = 0;
	this->_index = 0;
}

int	PhoneBook::get_index(void) const {
	return this->_index;
}

void	PhoneBook::set_index(int index) {
	this->_index = index;
}

std::string	PhoneBook::truncate(std::string word)
{
	std::string	newword;

	if (word.length() <= 10)
		return word;
	newword = word.substr(0, 9);
	newword += ".";
	return (newword);
}

int	PhoneBook::print_columns(int choices) {
	choices = 0;
	std::cout << GREEN << std::right << std::setw(10) << "   Index |";
	std::cout << std::right << std::setw(10) << " First   |";
	std::cout << std::right << std::setw(10) << " Last    |";
	std::cout << std::right << std::setw(10) << " Nickname" << COLOR_RESET << std::endl;
	if (this->contacts[0].get_first().length() == 0) {
		std::cout << "\t\t---empty---\n" << std::endl;
		return 0;
	}
	for (int i = 0; i < 8; i++) {
		if (this->contacts[i].get_first().length()) {
			std::cout << std::right << std::setw(10) << i;
			std::cout << std::right << std::setw(10) << this->truncate(this->contacts[i].get_first());
			std::cout << std::right << std::setw(10) << this->truncate(this->contacts[i].get_last());
			std::cout << std::right << std::setw(10) << this->truncate(this->contacts[i].get_nick()) << std::endl;
			choices++;
		}
	}
	std::cout << "\n" << std::endl;
	return choices;
}

void	PhoneBook::selected_contact(int i) const {
	std::cout << GREEN << "\nDisplaying information for contact..." << COLOR_RESET << std::endl;
	std::cout << "First Name     - " << this->contacts[i].get_first() << std::endl;
	std::cout << "Last Name      - " << this->contacts[i].get_last() << std::endl;
	std::cout << "Nickname       - " << this->contacts[i].get_nick() << std::endl;
	std::cout << "Phone Number   - " << this->contacts[i].get_phone() << std::endl;
	std::cout << "Darkest Secret - " << this->contacts[i].get_secret() << "\n" << std::endl;
}
void PhoneBook::display_contact() {
	std::string choice;
	int choices = this->print_columns(choices);

	while (!choice.length()) {
		int result;
		std::cout << "Enter index choice or type EXIT to return to main menu " << std::endl;
		std::cout << "->";
		std::getline(std::cin, choice);
		if (choice == "EXIT")
			return ;
		try {
			result = std::stoi(choice);
			if (result >= 0 && result < choices)
				selected_contact(result);
			else {
				std::cout << RED << "Invalid index choice" << COLOR_RESET << std::endl;
				choice.clear();
			}

		}
		catch (const std::exception) {
			std::cout << RED << "Invalid index choice. Try again or type EXIT to leave " << COLOR_RESET <<  std::endl;
			choice.clear();
		}
	}

};

std::string	PhoneBook::add_contact_helper(const std::string& prompt) {
	std::string temp;
	std::cout << GREEN << prompt << COLOR_RESET << std::endl;
	std::getline(std::cin, temp);
	while (temp.length() == 0) {
		std::cout << RED << "Field cannot be empty: " << COLOR_RESET << prompt << std::endl;
		std::getline(std::cin, temp);
	}
	return temp;
}

void	PhoneBook::add_contact() {
	Contact		newContact;
	std::string input;
	int index = this->get_index();
	if (index == 8) {
		std::cout << RED << "Phonebook full, will overwrite oldest entry" << COLOR_RESET << std::endl;
		this->set_index(0);
		index = this->get_index();
	}
	input = this->add_contact_helper("Enter first name");
	newContact.set_first(input);
	input = this->add_contact_helper("Enter last name");
	newContact.set_last(input);
	input = this->add_contact_helper("Enter nick name");
	newContact.set_nick(input);
	input = this->add_contact_helper("Enter phone number");
	newContact.set_phone(input);
	input = this->add_contact_helper("Enter darkest secret");
	newContact.set_secret(input);
	this->contacts[index] = newContact;
	this->set_index(++index);
	std::cout << "New Contact Added To Phonebook!" << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout << GREEN << "Thank you for using PhoneBook!" << COLOR_RESET << std::endl;
	std::cout << GREEN << "Comeback soon :)" << COLOR_RESET << std::endl;
}