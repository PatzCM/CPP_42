#include "Harl.hpp"


Harl::Harl() {}
Harl::~Harl() {}

void	Harl::complain(std::string level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error 
	};

	if (level.empty()) {
		std::cout << "No level provided!" << std::endl;
		return;
	}
	for (size_t i = 0; i < level.length(); i++)
	{
		level[i] = toupper(level[i]);
	}

	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR") {
		std::cout << "Unknown level: " << level << std::endl;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level){
			(this->*functions[i])();
			return;
		}
	}
}

void Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "Did you know Sabalenka's serve is one of the fastest reaching 200 km/h?" << std::endl;
}

void Harl::info() {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "Sabalenka's aggressive playing style has made her a formidable opponent on the court." << std::endl;
}

void Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "Sabalenka did a double fault! It doesn't seem like her but she still has the edge!" << std::endl;
}

void Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "Sabalenka wouldn't agree with this statement! It's unnaceptable!" << std::endl;
}
