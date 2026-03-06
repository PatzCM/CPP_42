#include "Dog.hpp"

Dog::Dog() {
		std::cout << "Dog default constructor called" << std::endl;
		type = "Dog";
		_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
	type = other.type;

}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	this->_brain = new Brain(*other._brain);
	this->type = other.type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}

std::string Dog::getType() const {
	return this->type;
}
