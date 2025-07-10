#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	std::cout << "Constructor called for " << name << std::endl;
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB() {
	std::cout << "Destructor called for " << this->name << std::endl;
	// Destructor
}

void HumanB::attack() {
	if (this->weapon) {
		std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
	} else {
		std::cout << this->name << " has no weapon to attack with!" << std::endl;
	}
}

void HumanB::setWeapon(Weapon &weapon) {
	std::cout << "Setting weapon for " << this->name << std::endl;
	this->weapon = &weapon;
}


