#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) {
	this->weapon = &weapon;
		this->name = name;
}

HumanA::~HumanA() {
	// Destructor
}

void HumanA::attack() {
	std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}
