#include "PhoneBook.hpp"
void showContacts(Contacts contacts[], int index);
std::string truncate(std::string str);

int main() {
	PhoneBook phoneBook;
	int index = 0;
	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::string cmd;
		std::cin >> cmd;

		if (cmd == "ADD") {
			phoneBook.addContact(index, phoneBook.contacts);
			index = (index + 1) % 8;
		}
		else if (cmd == "SEARCH") 
		{
			std::cout << std::setw(10) << std::left << "Index" << '|'
			          << std::setw(10) << std::left << "First Name" << '|'
			          << std::setw(10) << std::left << "Last Name" << '|'
			          << std::setw(10) << std::left << "Nickname" << std::endl;
			for (int i = 0; i < 8; i++) {
				if (!phoneBook.contacts[i].getFirstName().empty()) {
					showContacts(phoneBook.contacts, i);
				}
			}
		}
	}
}

void showContacts(Contacts contacts[], int index) {
	if (index < 0 || index >= 8) {
		std::cout << "Index out of bounds." << std::endl;
		return;
	}
	std::cout << std::setw(10) << std::left << index << '|'
		<< truncate(contacts[index].getFirstName()) << '|'
		<< truncate(contacts[index].getLastName()) << '|'
		<< truncate(contacts[index].getNickname()) << std::endl;
}

std::string truncate(std::string str) {
 if (str.length() > 10) {
		return str.substr(0, 9) + ".";
	}
	else {
		return std::string(10 - str.length(), ' ') + str;
	}
}
