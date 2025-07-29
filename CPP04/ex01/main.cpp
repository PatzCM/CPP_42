#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  const Animal* animals[4];
	for (int i = 0; i < 2; i++) 
		animals[i] = new Cat();
	for (int i = 2; i < 4; i++)
		animals[i] = new Dog();
	for (int i = 0; i < 4; i++) {
		std::cout << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
		delete animals[i];
	}

  return 0;

}
