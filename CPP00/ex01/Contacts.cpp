#include "Contacts.hpp"

Contacts::Contacts() {
		// Constructor implementation
}
Contacts::~Contacts() {
		// Destructor implementation
}

Contacts::Contacts(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret) {
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

std::string Contacts::getFirstName() const {
	return firstName;
}

std::string Contacts::getLastName() const {
	return lastName;
}

std::string Contacts::getNickname() const {
	return nickname;
}

std::string Contacts::getPhoneNumber() const {
	return phoneNumber;
}

std::string Contacts::getDarkestSecret() const {
	return darkestSecret;
}

