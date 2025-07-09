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
	std::cout << "First Name: ";
	std::cin >> firstName;
	if (!firstName.size())
		return ;
	contacts[index].setFirstName(firstName);
	std::cout << "Last Name: ";
	std::cin >> lastName; 
	if (!lastName.size())
		return ;
	contacts[index].setLastName(lastName);
	std::cout << "Nickname: ";
	std::cin >> nickname;
	if (!nickname.size())
		return ;
	contacts[index].setNickname(nickname);
	std::cout << "Phone Number: ";
	std::cin >> phoneNumber;
	if (!phoneNumber.size())
		return ;
	contacts[index].setPhoneNumber(phoneNumber);
	std::cout << "Darkest Secret: ";
	std::cin >> darkestSecret;
	if (!darkestSecret.size())
		return ;
	contacts[index].setDarkestSecret(darkestSecret);
	std::cout << "Contact added at index " << index << "." << std::endl;
}


