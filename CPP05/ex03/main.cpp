#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL));

    Intern someRandomIntern;
    AForm* rrf;

    std::cout << "=== Test from PDF example ===" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        Bureaucrat b("Boss", 45);
        b.signForm(*rrf);
        b.executeForm(*rrf);
        delete rrf;
    }

    std::cout << std::endl << "=== Test shrubbery creation ===" << std::endl;
    AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
    if (shrubbery) {
        Bureaucrat b("Alice", 137);
        b.signForm(*shrubbery);
        b.executeForm(*shrubbery);
        delete shrubbery;
    }

    std::cout << std::endl << "=== Test presidential pardon ===" << std::endl;
    AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    if (pardon) {
        Bureaucrat b("Charlie", 5);
        b.signForm(*pardon);
        b.executeForm(*pardon);
        delete pardon;
    }

    std::cout << std::endl << "=== Test unknown form ===" << std::endl;
    AForm* unknown = someRandomIntern.makeForm("coffee form", "me");
    if (unknown)
        delete unknown;

    return 0;
}
