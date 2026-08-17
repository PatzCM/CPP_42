#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) { return *this; }
Intern::~Intern() {}

static AForm* makeShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* makeRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* makePardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    struct FormEntry {
        const char* name;
        AForm* (*create)(const std::string&);
    };

    FormEntry forms[] = {
        {"shrubbery creation", makeShrubbery},
        {"robotomy request",   makeRobotomy},
        {"presidential pardon", makePardon}
    };

    for (size_t i = 0; i < 3; i++) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }

    std::cerr << "Error: form '" << formName << "' does not exist." << std::endl;
    return NULL;
}
