#ifndef CPP01__WEAPON__HPP
#define	CPP01__WEAPON__HPP

# include <iostream>

class Weapon {
private:
	std::string	_type;

public:
	Weapon(const std::string type);
	~Weapon();
	const std::string& 	getType() ;
	void			setType(const std::string);
};

#endif