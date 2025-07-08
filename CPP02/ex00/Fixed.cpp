#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
		this->fixedPointValue = raw ;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointValue ;

}

Fixed::Fixed( const Fixed &other) : fixedPointValue(other.fixedPointValue) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->fixedPointValue = other.fixedPointValue;
	}
	return *this;
}
