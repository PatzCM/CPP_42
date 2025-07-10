#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  
	std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // will output the cat sound!
  j->makeSound();
  meta->makeSound();

	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << " " << std::endl;
	std::cout << wrongMeta->getType() << " " << std::endl;
	wrongCat->makeSound(); // will output the Animal sound if done correctly... because its a wrongCat!
	wrongMeta->makeSound();

  return 0;

}
