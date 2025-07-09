#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
{
	std::cout << "ClapTrap constructor called for " << name << std::endl;
	this->name = name;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints == 0)
	{
		std::cout << name << " has no energy left to attack!" << std::endl;
		return;
	}
	std::cout << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints = (amount >= hitPoints) ? 0 : hitPoints - amount;
	if (hitPoints == 0)
	{
		std::cout << name << " has been destroyed!" << std::endl;
		return;
	}
	std::cout << name << " takes " << amount << " points of damage! Hit points left: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints == 0)
	{
		std::cout << name << " has no energy left to repair itself!" << std::endl;
		return;
	}

	hitPoints += amount;
	std::cout << name << " repairs itself for " << amount << " points! Hit points now: " << hitPoints << std::endl;
	energyPoints--;
}
