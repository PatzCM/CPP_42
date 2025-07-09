#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constructor called" << std::endl;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string& name)
{
	std::cout << "ClapTrap constructor called for " << name << std::endl;
	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called for " << other.name << std::endl;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap assignment operator called for " << other.name << std::endl;
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints == 0 || hitPoints == 0)
	{
		std::cout << name << " has no way to attack!" << std::endl;
		return;
	}
	std::cout << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints = (amount >= hitPoints) ? 0 : hitPoints - amount;
	std::cout << name << " takes " << amount << " points of damage! Hit points left: " << hitPoints << std::endl;
	if (hitPoints == 0)
		std::cout << name << " has been destroyed!" << std::endl;
	}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0)
	{
		hitPoints += amount;
		std::cout << name << " repairs itself for " << amount << " points! Hit points now: " << hitPoints << std::endl;
		energyPoints--;
	}
	else 
		std::cout << name << " has no energy left to repair itself!" << std::endl;
}
