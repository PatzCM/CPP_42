#include <iostream>
#include <stdint.h>
#include "Serializer.hpp"

int main()
{
	Data data;
	data.value = 42;
	data.name = "TestStruct";

	std::cout << "Original Data:" << std::endl;
	std::cout << "  Address: " << &data << std::endl;
	std::cout << "  Value: " << data.value << std::endl;
	std::cout << "  Name: " << data.name << std::endl;

	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "\nSerialized: " << serialized << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "\nDeserialized Data:" << std::endl;
	std::cout << "  Address: " << deserialized << std::endl;
	std::cout << "  Value: " << deserialized->value << std::endl;
	std::cout << "  Name: " << deserialized->name << std::endl;

	if (deserialized == &data)
		std::cout << "\nSUCCESS: Pointers match!" << std::endl;
	else
		std::cout << "\nFAILURE: Pointers don't match!" << std::endl;

	return 0;
}
