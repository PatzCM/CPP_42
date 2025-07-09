#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
		this->hitPoints = 100;
		this->energyPoints = 50;
		this->attackDamage = 20;
		std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap parameterized constructor called for " << this->name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called for " << this->name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "ScavTrap assignment operator called for " << this->name << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called for " << this->name << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		std::cout << "ScavTrap " << this->name << " attacks " << target 
							<< " dealing " << this->attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->name << " cannot attack." << std::endl;
}
