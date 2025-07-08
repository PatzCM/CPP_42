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

int Fixed::toInt() const {
	return this->fixedPointValue >> fractionalBits;
}

float Fixed::toFloat() const {
	return static_cast<float>(this->fixedPointValue) / (1 << fractionalBits);
}

Fixed Fixed::operator > (const Fixed &other) const {
	return Fixed(this->getRawBits() > other.getRawBits());
}

Fixed Fixed::operator < (const Fixed &other) const {
	return Fixed(this->getRawBits() < other.getRawBits());
}

Fixed Fixed::operator >= (const Fixed &other) const {
	return Fixed(this->getRawBits() >= other.getRawBits());
}

Fixed Fixed::operator <= (const Fixed &other) const {
	return Fixed(this->getRawBits() <= other.getRawBits());
}

Fixed Fixed::operator == (const Fixed &other) const {
	return Fixed(this->getRawBits() == other.getRawBits());
}

Fixed Fixed::operator != (const Fixed &other) const {
	return Fixed(this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator + (const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator - (const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed:: operator * (const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator / (const Fixed &other) const {
	if (other.toFloat() == 0) {
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed(0); // or handle error appropriately
	}
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator ++ () {
	++this->fixedPointValue;
	return *this;	
}

Fixed Fixed::operator ++ (int) {
	Fixed temp = *this;
	++(*this);
	return temp; 
}

Fixed &Fixed::operator -- () {
	--this->fixedPointValue;
	return *this; 
}
Fixed Fixed::operator -- (int) {
	Fixed temp = *this;
	--(*this);
	return temp; 
}

std::ostream& operator << (std::ostream &os, const Fixed &value) {
	os << value.toFloat();
	return os;
}
