#include "Contact.hpp"

Contact::Contact(void) {

}

std::string Contact::get_first(void) const {
	return this->_first;
}

std::string Contact::get_last(void) const {
	return this->_last;
}

std::string Contact::get_nick(void) const {
	return this->_nick;
}

std::string Contact::get_phone(void) const {
	return this->_phone;
}

std::string Contact::get_secret(void) const {
	return this->_secret;
}

void	Contact::set_first(const std::string& first) {
	this->_first = first;
}

void	Contact::set_last(const std::string& last) {
	this->_last = last;
}

void	Contact::set_nick(const std::string& nick) {
	this->_nick = nick;
}

void	Contact::set_phone(const std::string& phone) {
	this->_phone = phone;
}

void	Contact::set_secret(const std::string& secret) {
	this->_secret = secret;
}

