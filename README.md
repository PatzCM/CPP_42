# CPP 42

My implementations of the C++ modules from the 42 school curriculum. Each module progressively introduces fundamental C++ concepts from basic I/O and memory management through to advanced topics like polymorphism, exception handling, and type casting.

---

## CPP00 — Basic C++ Concepts

| Exercise | Description |
|----------|-------------|
| **ex00 - Megaphone** | Converts input strings to uppercase. Introduction to basic C++ I/O. |
| **ex01 - PhoneBook** | A contact management application storing up to 8 contacts with fields like name, phone number, and nickname. Uses classes with getters/setters and input validation. |

---

## CPP01 — Memory and Pointers

| Exercise | Description |
|----------|-------------|
| **ex00 - Zombie** | Demonstrates heap vs stack allocation with `newZombie()` and `randomChump()` functions. |
| **ex01 - Zombie Horde** | Allocates arrays of objects on the heap using `zombieHorde()`. |
| **ex02 - References** | Shows the difference between pointers and references through address/value comparisons. |
| **ex03 - Weapon System** | Practical differences between reference and pointer-based composition using `HumanA` and `HumanB` classes with a `Weapon` class. |
| **ex04 - Sed** | File string replacement tool. Reads a file, replaces all occurrences of a string, and writes to a new file. |
| **ex05 - Harl** | Complaint level system using function pointers to dispatch debug, info, warning, and error messages. |

---

## CPP02 — Operator Overloading

| Exercise | Description |
|----------|-------------|
| **ex00 - Fixed (Basic)** | Introduction to fixed-point number representation with 8 fractional bits. Implements copy constructor and assignment operator. |
| **ex01 - Fixed (Conversions)** | Adds int/float constructors, `toFloat()`, `toInt()`, and output stream operator (`<<`). |
| **ex02 - Fixed (Full)** | Complete operator overloading: comparison (`>`, `<`, `>=`, `<=`, `==`, `!=`), arithmetic (`+`, `-`, `*`, `/`), increment/decrement (`++`, `--`), and static `min()`/`max()`. |

---

## CPP03 — Inheritance

| Exercise | Description |
|----------|-------------|
| **ex00 - ClapTrap** | Base robot class with hit points, energy points, and attack damage. Methods: `attack()`, `takeDamage()`, `beRepaired()`. |
| **ex01 - ScavTrap** | Single inheritance from ClapTrap. Overrides `attack()` and adds `guardGate()`. |
| **ex02 - FragTrap** | Another derived class from ClapTrap with `highFivesGuys()`. Demonstrates multiple derived classes from a single base. |

---

## CPP04 — Polymorphism and Abstract Classes

| Exercise | Description |
|----------|-------------|
| **ex00 - Animal Polymorphism** | Virtual `makeSound()` method with `Cat` and `Dog` overrides. Includes `WrongAnimal`/`WrongCat` to contrast non-virtual dispatch. |
| **ex01 - Brain Composition** | Animals own `Brain` objects (array of 100 ideas). Demonstrates deep copying and proper copy semantics. |
| **ex02 - Abstract Classes** | `Animal` becomes a pure abstract class. Enforces implementation of pure virtual functions in derived classes. |

---

## CPP05 — Exception Handling

| Exercise | Description |
|----------|-------------|
| **ex00 - Bureaucrat** | Custom exceptions (`GradeTooHighException`, `GradeTooLowException`) thrown during grade modifications (valid range: 1–150). |
| **ex01 - Form** | Relationship between `Bureaucrat` and `Form` classes. Bureaucrats sign forms based on grade requirements, with exception handling for invalid operations. |

---

## CPP06 — Type Casting

| Exercise | Description |
|----------|-------------|
| **ex00 - ScalarConverter** | Static utility class converting string literals to char, int, float, and double. Demonstrates `static_cast`. |
| **ex01 - Serializer** | Pointer-to-integer casting using `reinterpret_cast`. Serializes/deserializes `Data` pointers via `uintptr_t`. |
| **ex02 - Identify** | RTTI and `dynamic_cast`. Randomly generates `A`, `B`, or `C` objects and identifies their type at runtime. |

---

## Building

Each exercise contains its own `Makefile`. To compile:

```bash
cd CPP0X/ex0X
make
```
