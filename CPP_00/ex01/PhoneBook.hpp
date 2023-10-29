#ifndef CPP_00_PHONEBOOK_HPP
#define CPP_00_PHONEBOOK_HPP

# include "Contact.hpp"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define COLOR_RESET   "\x1b[0m"

class PhoneBook {
private:
	int 		_index;
	Contact 	contacts[8];
	int			print_columns(int choices);
	void		selected_contact(int i) const;
	std::string	add_contact_helper(const std::string& prompt);
	std::string	truncate(std::string word);

public:
	PhoneBook();
	~PhoneBook();
	int		phoneBookSize;
	void	storeContact(const Contact& contact);
	int		get_index(void) const;
	void	set_index(int index);
	void	display_contact();
	void	add_contact();
};


#endif //CPP_00_PHONEBOOK_HPP
