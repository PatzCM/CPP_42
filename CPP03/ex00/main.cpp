#include "ClapTrap.hpp"

int main() {
  ClapTrap claptrap("CLTP");

  claptrap.attack("target1");
  claptrap.takeDamage(5);
  claptrap.beRepaired(3);
  claptrap.attack("target2");
  claptrap.takeDamage(10);
  claptrap.attack("");
  claptrap.beRepaired(200);
  claptrap.beRepaired(2);
  claptrap.takeDamage(10);
  claptrap.takeDamage(100);

  claptrap.beRepaired(2);

  return 0;
}
