#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value) : fixedPointValue(value << fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : fixedPointValue(static_cast<int>(roundf(value * (1 << fractionalBits)))) {
	std::cout << "Float constructor called" << std::endl;
}
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
		this->fixedPointValue = raw ;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointValue ;

}

Fixed::Fixed( const Fixed &other)  {
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPointValue = other.fixedPointValue;
}

Fixed &Fixed::operator=(const Fixed &other) {
std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->fixedPointValue = other.fixedPointValue;
	}
	return *this;
}

int Fixed::toInt() const {
	return this->fixedPointValue >> fractionalBits;
}

float Fixed::toFloat() const {
	return static_cast<float>(this->fixedPointValue) / (1 << fractionalBits);
}

std::ostream& operator << (std::ostream &os, const Fixed &value) {
	os << value.toFloat();
	return os;
}
