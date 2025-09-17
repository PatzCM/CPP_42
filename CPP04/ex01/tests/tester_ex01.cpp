// Turn private into public ONLY IN THIS FILE (test hack)
#define private public
#include "../ex01/Dog.hpp"
#include "../ex01/Cat.hpp"
#include "../ex01/Animal.hpp"
#include "../ex01/Brain.hpp"
#undef private

#include <iostream>

static void line(const std::string &title) {
    std::cout << "\n========== " << title << " ==========\n";
}

static void fillDogIdeas(Dog &d, const std::string &base) {
    // We only fill first few indices for clarity
    for (int i = 0; i < 5; ++i)
        d._brain->ideas[i] = base + " idea#" + std::string(1, '0' + i);
}

static void showDogIdeas(const Dog &d, const std::string &label) {
    std::cout << label << " brain@" << d._brain << "\n";
    for (int i = 0; i < 5; ++i)
        std::cout << "  [" << i << "] " << d._brain->ideas[i] << "\n";
}

static void fillCatIdeas(Cat &c, const std::string &base) {
    for (int i = 0; i < 5; ++i)
        c._brain->ideas[i] = base + " idea#" + std::string(1, '0' + i);
}

static void showCatIdeas(const Cat &c, const std::string &label) {
    std::cout << label << " brain@" << c._brain << "\n";
    for (int i = 0; i < 5; ++i)
        std::cout << "  [" << i << "] " << c._brain->ideas[i] << "\n";
}

static void test_dog_copy_ctor() {
    line("DOG COPY CONSTRUCTOR DEEP COPY TEST");
    Dog original;
    fillDogIdeas(original, "ORIG");

    Dog copy = original; // invokes copy ctor
    showDogIdeas(original, "Original before change");
    showDogIdeas(copy,    "Copy before change");

    // Change original's first two ideas
    original._brain->ideas[0] = "CHANGED_0";
    original._brain->ideas[1] = "CHANGED_1";

    std::cout << "\nAfter modifying original:\n";
    showDogIdeas(original, "Original modified");
    showDogIdeas(copy,    "Copy should remain with old values");

    if (original._brain != copy._brain)
        std::cout << "OK: Distinct Brain pointers.\n";
    else
        std::cout << "ERROR: SAME Brain pointer (shallow)!\n";
}

static void test_dog_assignment() {
    line("DOG ASSIGNMENT OPERATOR DEEP COPY TEST");
    Dog a;
    Dog b;
    fillDogIdeas(a, "AAA");
    fillDogIdeas(b, "BBB");

    std::cout << "Before assignment:\n";
    showDogIdeas(a, "a");
    showDogIdeas(b, "b");

    b = a; // operator=
    std::cout << "\nAfter b = a:\n";
    showDogIdeas(a, "a");
    showDogIdeas(b, "b (should match a but different brain ptr)");

    a._brain->ideas[0] = "a changed after assign";
    std::cout << "\nAfter changing a[0]:\n";
    showDogIdeas(a, "a modified");
    showDogIdeas(b, "b should be unchanged at index 0");

    if (a._brain != b._brain)
        std::cout << "OK: Distinct Brain pointers.\n";
    else
        std::cout << "ERROR: SAME Brain pointer.\n";

    std::cout << "\nSelf-assignment (b = b) test:\n";
    b = b;
    showDogIdeas(b, "b after self-assign");
}

static void test_cat_copy_and_assign() {
    line("CAT COPY & ASSIGN TEST");
    Cat c1;
    fillCatIdeas(c1, "CAT1");
    Cat c2(c1); // copy ctor
    showCatIdeas(c1, "c1");
    showCatIdeas(c2, "c2 copy");

    c1._brain->ideas[0] = "c1 changed";
    std::cout << "\nAfter modifying c1:\n";
    showCatIdeas(c1, "c1 mod");
    showCatIdeas(c2, "c2 should be old values");

    Cat c3;
    fillCatIdeas(c3, "CAT3");
    std::cout << "\nBefore assignment c3 = c1:\n";
    showCatIdeas(c3, "c3");
    c3 = c1;
    std::cout << "After assignment c3 = c1:\n";
    showCatIdeas(c3, "c3 now copy of c1");
    if (c1._brain != c3._brain)
        std::cout << "OK brain distinct\n";
    else
        std::cout << "ERROR shallow copy\n";
}

static void test_polymorphic_array() {
    line("POLYMORPHIC ARRAY (HALF DOGS HALF CATS)");
    const int N = 6;
    Animal* animals[N];
    for (int i = 0; i < N/2; ++i)
        animals[i] = new Dog();
    for (int i = N/2; i < N; ++i)
        animals[i] = new Cat();

    std::cout << "\n-- Sounds --\n";
    for (int i = 0; i < N; ++i)
        animals[i]->makeSound();

    std::cout << "\n-- Deleting --\n";
    for (int i = 0; i < N; ++i)
        delete animals[i];
}

int main() {
    test_dog_copy_ctor();
    test_dog_assignment();
    test_cat_copy_and_assign();
    test_polymorphic_array();
    return 0;
}
