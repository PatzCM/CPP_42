#import "Zombie.hpp"

Zombie::Zombie() {
	// Constructor
}

Zombie::Zombie(std::string name) : _name(name) {
	// Constructor with name
	std::cout << this->_name << " created" << std::endl;
}

Zombie::~Zombie(){
	std::cout << this->_name << " destroyed" << std::endl;
}

void Zombie::setName(std::string name) {
	this->_name = name;
}

void Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
