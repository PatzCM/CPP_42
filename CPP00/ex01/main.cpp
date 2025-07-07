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
			std::cout << "Enter index to view details: ";
			int viewIndex;
			std::cin >> viewIndex;
			if (viewIndex < 0 || viewIndex >= 8 || phoneBook.contacts[viewIndex].getFirstName().empty()) {
				std::cout << "Invalid index or contact does not exist." << std::endl;
			} else {
				std::cout << "First Name: " << phoneBook.contacts[viewIndex].getFirstName() << std::endl;
				std::cout << "Last Name: " << phoneBook.contacts[viewIndex].getLastName() << std::endl;
				std::cout << "Nickname: " << phoneBook.contacts[viewIndex].getNickname() << std::endl;
				std::cout << "Phone Number: " << phoneBook.contacts[viewIndex].getPhoneNumber() << std::endl;
				std::cout << "Darkest Secret: " << phoneBook.contacts[viewIndex].getDarkestSecret() << std::endl;
			}
		}
		else if (cmd == "EXIT") {
			std::cout << "Exiting the program." << std::endl;
			break;
		}
		else {
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
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
