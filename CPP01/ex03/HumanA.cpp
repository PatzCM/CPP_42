#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) {
	std::cout << "Constructor called for " << name << std::endl;
	this->weapon = &weapon;
		this->name = name;
}

HumanA::~HumanA() {
	std::cout << "Destructor called for " << this->name << std::endl;
}

void HumanA::attack() {
	std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}
