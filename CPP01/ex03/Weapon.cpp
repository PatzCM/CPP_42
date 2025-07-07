#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

const std::string &Weapon::getType()
{
	return this->type;
}

Weapon::~Weapon(){
	// Destructor
}


void Weapon::setType(std::string type)
{
	this->type = type;
}

