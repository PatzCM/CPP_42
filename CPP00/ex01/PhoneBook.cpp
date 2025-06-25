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
		index = 0; // Overwrite the oldest contac
	}
	std::cout << "Enter contact details:" << std::endl;
	std::cout << "First Name: ";
	std::cin >> firstName;
	contacts[index].setFirstName(firstName);
	std::cout << "Last Name: ";
	std::cin >> lastName; 
	contacts[index].setLastName(lastName);
	std::cout << "Nickname: ";
	std::cin >> nickname;
	contacts[index].setNickname(nickname);
	std::cout << "Phone Number: ";
	std::cin >> phoneNumber;
	contacts[index].setPhoneNumber(phoneNumber);
	std::cout << "Darkest Secret: ";
	std::cin >> darkestSecret;
	contacts[index].setDarkestSecret(darkestSecret);
	std::cout << "Contact added at index " << index << "." << std::endl;
}


