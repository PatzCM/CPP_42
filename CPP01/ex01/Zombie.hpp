#pragma once
#include <iostream>
#include <sstream>

class Zombie 
{
	private:
		std::string name;
	
	public:
		Zombie();
		~Zombie();
		void announce(void);
	  void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);
