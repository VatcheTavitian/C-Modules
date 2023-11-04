#ifndef CPP02_FIXED_HPP
#define CPP02_FIXED_HPP

# include <iostream>

class Fixed {
private:
	int		_fixed;
	const	static int _fBits = 8;

public:
	Fixed();
	Fixed(const Fixed& src);
	~Fixed();
	Fixed& operator=(const Fixed& src);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};


#endif //CPP02_FIXED_HPP
