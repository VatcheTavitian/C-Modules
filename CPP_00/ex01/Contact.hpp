#ifndef CPP_00_CONTACT_HPP
#define CPP_00_CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
private:
	std::string _first;
	std::string _last;
	std::string _nick;
	std::string	_phone;
	std::string _secret;

public:
	Contact(void);
//	~Contact(void);
	std::string get_first(void) const;
	std::string get_last(void) const;
	std::string get_nick(void) const;
	std::string get_phone(void) const;
	std::string get_secret(void) const;

	void	set_first(const std::string& first);
	void	set_last(const std::string& last);
	void	set_nick(const std::string& nick);
	void	set_phone(const std::string& phone);
	void	set_secret(const std::string& secret);
};


#endif //CPP_00_CONTACT_HPP
