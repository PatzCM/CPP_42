#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

static void line(const std::string& title) {
    std::cout << "\n========== " << title << " ==========\n";
}

static void printDogBrain(const Dog& d, const std::string& label) {
    const Brain* b = d.getBrain();
    std::cout << label << ": Object@" << &d << " Brain@" << b << "\n";
    std::cout << "  idea[0] = " << b->getIdea(0) << "\n";
    std::cout << "  idea[1] = " << b->getIdea(1) << "\n";
}

static void test_copy_constructor() {
    line("DOG COPY CONSTRUCTOR (DEEP COPY TEST)");
    Dog d1;
    d1.getBrain()->setIdea(0, "Chase the cat");
    d1.getBrain()->setIdea(1, "Guard the house");

    Dog d2(d1); // invokes copy constructor

    printDogBrain(d1, "Original d1 (before modifications)");
    printDogBrain(d2, "Copy d2 (after construction)");

    // Modify original after copy
    d1.getBrain()->setIdea(0, "Sleep");
    d1.getBrain()->setIdea(1, "Eat");

    std::cout << "\nAfter modifying d1's brain:\n";
    printDogBrain(d1, "Modified d1");
    printDogBrain(d2, "Unchanged d2 (should still have old ideas)");

    // Brain pointers must differ
    if (d1.getBrain() != d2.getBrain())
        std::cout << "OK: Distinct Brain pointers => deep copy.\n";
    else
        std::cout << "ERROR: Same Brain pointer => shallow copy!\n";
}

static void test_assignment_operator() {
    line("DOG ASSIGNMENT OPERATOR (DEEP COPY TEST)");
    Dog a;
    a.getBrain()->setIdea(0, "Dig");
    a.getBrain()->setIdea(1, "Howl");

    Dog b;
    b.getBrain()->setIdea(0, "Old idea 0");
    b.getBrain()->setIdea(1, "Old idea 1");

    std::cout << "Before assignment:\n";
    printDogBrain(a, "a");
    printDogBrain(b, "b");

    b = a; // operator=

    std::cout << "\nAfter b = a:\n";
    printDogBrain(a, "a");
    printDogBrain(b, "b (should match a now but have different Brain pointer)");

    // Modify a after assignment
    a.getBrain()->setIdea(0, "New thought A0");
    a.getBrain()->setIdea(1, "New thought A1");

    std::cout << "\nAfter modifying a post-assignment:\n";
    printDogBrain(a, "a (modified)");
    printDogBrain(b, "b (should still have previous copied values)");

    if (a.getBrain() != b.getBrain())
        std::cout << "OK: Distinct Brain pointers => deep copy.\n";
    else
        std::cout << "ERROR: Same Brain pointer => shallow copy!\n";

    // Self-assignment safety
    a = a;
    std::cout << "Self-assignment performed (no crash, no leak expected).\n";
}

static void test_polymorphic_array() {
    line("POLYMORPHIC ARRAY DELETION TEST");
    const size_t N = 6;
    Animal* animals[N];

    for (size_t i = 0; i < N; ++i) {
        if (i < N / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    // (Optional) set some ideas in first Dog and Cat
    Dog* d = dynamic_cast<Dog*>(animals[0]);
    if (d) d->getBrain()->setIdea(0, "Run fast");

    Cat* c = dynamic_cast<Cat*>(animals[N / 2]);
    if (c) c->getBrain()->setIdea(0, "Climb tree");

    for (size_t i = 0; i < N; ++i)
        delete animals[i]; // must call virtual destructors properly
}

static void test_cat_copy() {
    line("CAT COPY (SYMMETRY)");
    Cat c1;
    c1.getBrain()->setIdea(0, "Nap");
    Cat c2(c1);
    c1.getBrain()->setIdea(0, "Eat fish");

    std::cout << "c1 idea[0] = " << c1.getBrain()->getIdea(0) << "\n";
    std::cout << "c2 idea[0] = " << c2.getBrain()->getIdea(0) << "\n";
    if (c1.getBrain() != c2.getBrain())
        std::cout << "OK: Distinct Brain pointers.\n";
    else
        std::cout << "ERROR: Shallow copy in Cat.\n";
}

int main() {
    test_copy_constructor();
    test_assignment_operator();
    test_polymorphic_array();
    test_cat_copy();
    return 0;
}
// int main() {
// 	//  const Animal* animals[4];
// 	// for (int i = 0; i < 2; i++) 
// 	// 	animals[i] = new Cat();
// 	// for (int i = 2; i < 4; i++)
// 	// 	animals[i] = new Dog();
// 	// for (int i = 0; i < 4; i++) {
// 	// 	std::cout << animals[i]->getType() << std::endl;
// 	// 	animals[i]->makeSound();
// 	// 	delete animals[i];
// 	// }
// 	Dog basic;
// 	{
// 		Dog tmp = basic;
// 	}
//   return 0;
//
// }
