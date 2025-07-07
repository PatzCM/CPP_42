#include "Zombie.hpp"
#include <iostream>

int main() {
		Zombie* zombie = newZombie("Bob");
		zombie->announce();
		delete zombie;

		randomChump("Alice");

		return 0;
}
