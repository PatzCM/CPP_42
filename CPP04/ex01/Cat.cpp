#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
	type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	this->_brain = new Brain(*other._brain);
	this->type = other.type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

std::string Cat::getType() const {
	return this->type;
}
