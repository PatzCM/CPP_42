#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
  ClapTrap claptrap("CLTP");
	ScavTrap scavtrap("SCVT");
	FragTrap fragtrap("FRGT");
	ClapTrap defaultClaptrap;
	ScavTrap defaultScavtrap;
	FragTrap defaultFragtrap;

  claptrap.attack("target1");
  claptrap.takeDamage(5);
  claptrap.beRepaired(3);
	defaultClaptrap.attack("defaultTarget1");
	defaultClaptrap.takeDamage(2);
	defaultClaptrap.beRepaired(1);

	scavtrap.attack("target2");
	scavtrap.takeDamage(10);
	scavtrap.beRepaired(5);
	scavtrap.guardGate();
	fragtrap.attack("target3");
	fragtrap.takeDamage(15);
	fragtrap.beRepaired(7);
	fragtrap.highFivesGuys();

  return 0;
}
