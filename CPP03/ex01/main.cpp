#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  ClapTrap claptrap("CLTP");
	
	ScavTrap scavtrap("SCVT");

  claptrap.attack("target1");
  claptrap.takeDamage(5);
  claptrap.beRepaired(3);
	scavtrap.attack("target2");
	scavtrap.takeDamage(10);
	scavtrap.beRepaired(5);
	scavtrap.guardGate();


  return 0;
}
