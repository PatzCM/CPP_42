#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "generate.hpp"
#include "identify.hpp"

int main()
{
	std::cout << "=== Testing with pointer ===" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Base* ptr = generate();
		std::cout << "Generated: ";
		identify(ptr);
		delete ptr;
	}

	std::cout << "\n=== Testing with reference ===" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Base* ptr = generate();
		std::cout << "Generated: ";
		identify(*ptr);
		delete ptr;
	}

	return 0;
}
