#pragma once

#include <iomanip>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <ctime>
#include <string>
#include "Contacts.hpp"


class PhoneBook {
public:	
	Contacts contacts[8]; // Array of Contacts	
	PhoneBook(); // Constructor
	~PhoneBook(); // Destructor
	void addContact(int index, Contacts contacts[]);
};
