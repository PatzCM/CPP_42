#include <iostream>
#include <iomanip>
#include "Contacts.hpp"

class PhoneBook {
public:	
	Contacts contacts[8]; // Array of Contacts	
	PhoneBook(); // Constructor
	~PhoneBook(); // Destructor
	void addContact(int index, Contacts contacts[]);
};
