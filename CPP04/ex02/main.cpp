#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

static void line(const std::string& title) {
    std::cout << "\n========== " << title << " ==========\n";
}


int main() {
	line("Animal test");
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << "j " << std::endl;
	std::cout << i->getType() << "i " << std::endl;
	
	line("Test abstract animal");
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	delete i;
	delete j;
}
