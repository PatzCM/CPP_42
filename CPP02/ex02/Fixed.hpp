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
	Fixed(const Fixed& other);

// Assignment Operator ----------------------------------------
	Fixed& operator = (const Fixed& other);
	bool operator > (const Fixed& other) const;
	bool operator < (const Fixed& other) const;
	bool operator >= (const Fixed& other) const;
	bool operator <= (const Fixed& other) const;
	bool operator == (const Fixed& other) const;
	bool operator != (const Fixed& other) const;

// Arithmetic Operators --------------------------------------
	Fixed operator + (const Fixed& other) const;
	Fixed operator - (const Fixed& other) const;
	Fixed operator * (const Fixed& other) const;
	Fixed operator / (const Fixed& other) const;

// Increment and Decrement Operators --------------------------
	Fixed& operator ++ (); // pre-increment
	Fixed operator ++ (int); // post-increment
	Fixed& operator -- (); // pre-decrement
	Fixed operator -- (int); // post-decrement

// Min and Max Functions --------------------------------------
	static Fixed&	min(Fixed& a, Fixed& b);	
	static Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&	max(Fixed& a, Fixed& b);
	static Fixed&	max(const Fixed& a, const Fixed& b);

// Member Functions -------------------------------------------
	int getRawBits() const;
	void setRawBits(int const value);
	float toFloat() const;
	int toInt() const;
};

std::ostream& operator << (std::ostream &os, const Fixed &value);


