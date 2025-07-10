#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	std::cout << "Constructor called for weapon of type: " << type << std::endl;
	this->type = type;
}

const std::string &Weapon::getType()
{
	return this->type;
}

Weapon::~Weapon(){
	std::cout << "Destructor called for weapon of type: " << this->type << std::endl;
	// Destructor
}


void Weapon::setType(std::string type)
{
	this->type = type;
}

