#pragma once

#include <iostream>
#include <cmath>

class Fixed {
private:
	int fixedPointValue;
	static const int fractionalBits = 8;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);

	int getRawBits() const;
	void setRawBits(int const value);

	float toFloat() const;
	int toInt() const;
};

std::ostream& operator << (std::ostream &os, const Fixed &value);


