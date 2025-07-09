#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
		// Constructor implementation
}
PhoneBook::~PhoneBook() {
		// Destructor implementation
}

void PhoneBook::addContact(int index, Contacts contacts[]) {
	std::string input, firstName, lastName, nickname, phoneNumber, darkestSecret;
	
	if (index < 0 || index >= 8) {
		std::cout << "Index out of bounds. Only 8 contacts can be stored." << std::endl;
		return;
	}
	if (!contacts[7].getFirstName().empty()) {
		std::cout << "8 contacts already stored. Overwriting the oldest contact." << std::endl;
	}
	std::cout << "Enter contact details:" << std::endl;
	if ((firstName = contacts->setString("First Name: ")) == "-1") return; 
	contacts[index].setFirstName(firstName);
	if ((lastName = contacts[index].setString("Last Name: ")) == "-1") return;
	contacts[index].setLastName(lastName);
	if ((nickname =	contacts[index].setString("Nickname: ")) == "-1") return;
	contacts[index].setNickname(nickname);
	if ((phoneNumber = contacts[index].setNumber("Phone Number: ")) == "-1") return;
	contacts[index].setPhoneNumber(phoneNumber);
	if ((darkestSecret = contacts[index].setString("Darkest Secret: ")) == "-1") return;
	contacts[index].setDarkestSecret(darkestSecret);
	std::cout << "Contact added at index " << index << "." << std::endl;
}


