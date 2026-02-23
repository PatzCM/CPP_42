#pragma once

#include <iostream>
#include <string>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &other);
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const &other);
	


private:
	std::string const _name;
	int _grade;
}

