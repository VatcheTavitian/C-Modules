#ifndef CPP02_FIXED_HPP
#define CPP02_FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
private:
	int		_fixed;
	const	static int _fBits = 8;

public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed& src);
	~Fixed();
	Fixed& operator=(const Fixed& src);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& src);

#endif //CPP02_FIXED_HPP
