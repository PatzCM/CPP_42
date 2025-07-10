#include "Zombie.hpp"
#include <iostream>

int main() {
		Zombie* zombie = newZombie("Bob");
		zombie->announce();
		delete zombie;
		Zombie* zombie2 = new Zombie("Alice");
		randomChump("Charlie");
		randomChump("Alice");
		zombie2->announce();
		return 0;
}
