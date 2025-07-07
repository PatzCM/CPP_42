#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB() {
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
	this->weapon = &weapon;
}


