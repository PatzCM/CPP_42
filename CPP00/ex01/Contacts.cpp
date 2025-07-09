#include "Contacts.hpp"

Contacts::Contacts() {
  // Constructor implementation
}
Contacts::~Contacts() {
  // Destructor implementation
}

Contacts::Contacts(std::string firstName, std::string lastName,
                   std::string nickname, std::string phoneNumber,
                   std::string darkestSecret) {
  this->firstName = firstName;
  this->lastName = lastName;
  this->nickname = nickname;
  this->phoneNumber = phoneNumber;
  this->darkestSecret = darkestSecret;
}

void Contacts::setFirstName(const std::string firstName) {
  this->firstName = firstName;
}

void Contacts::setLastName(const std::string lastName) {
  this->lastName = lastName;
}

void Contacts::setNickname(const std::string nickname) {
  this->nickname = nickname;
}

void Contacts::setPhoneNumber(const std::string phoneNumber) {
  this->phoneNumber = phoneNumber;
}

void Contacts::setDarkestSecret(const std::string darkestSecret) {
  this->darkestSecret = darkestSecret;
}

std::string Contacts::getFirstName() const { return firstName; }

std::string Contacts::getLastName() const { return lastName; }

std::string Contacts::getNickname() const { return nickname; }

std::string Contacts::getPhoneNumber() const { return phoneNumber; }

std::string Contacts::getDarkestSecret() const { return darkestSecret; }

std::string Contacts::setString(std::string str) {

  std::string input;
	std::cout << str;
	while (1) {
		std::getline(std::cin, input);
  	if (std::cin.eof()) {
			std::cout << "End of input detected. Exiting." << std::endl;
			return "-1"; // Handle end of input gracefully
		}
		if (trimSpaces(input) == "-1") {
			std::cout << "Input cannot be empty. Please enter a valid string." << std::endl;
			continue;
		}
		else {
			input = trimSpaces(input); // Trim spaces from input	
			return input; // Return the valid input
		}
	}
}
std::string Contacts::setNumber(std::string str) {
  std::string input;

	std::cout << str;
	std::cin.ignore(); // Clear the input buffer before getline
  while (1) {
    std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << "End of input detected. Exiting." << std::endl;
			return "-1"; // Handle end of input gracefully
		}
		if (!input.empty() && std::cin.good()) {
			if (input.find_first_not_of("0123456789") != std::string::npos) {
			// Check if the input contains any non-digit characters
      std::cout << "Invalid number. Please enter a valid number." << std::endl;
			}
			else
				return input;
		} else {
			std::cin.clear();
			std::cout << "Invalid input. Please enter a valid number." << std::endl;
		}
	}
}

std::string Contacts::trimSpaces(const std::string str) {
	std::string trimmed = str;
	trimmed.erase(0, trimmed.find_first_not_of(' ')); // Trim leading spaces
	trimmed.erase(trimmed.find_last_not_of(' ') + 1); // Trim trailing spaces
	if (trimmed.empty())
		return "-1";
	return trimmed;
}

