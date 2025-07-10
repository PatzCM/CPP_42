#pragma once

#include "Animal.hpp"
#include <iostream>

class WrongAnimal {
protected:
  std::string type;

public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal &other);
  ~WrongAnimal();

  WrongAnimal &operator=(const WrongAnimal &other);

  void makeSound() const;
  std::string getType() const;
};
