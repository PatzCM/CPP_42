#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL));

    std::cout << "=== Test ShrubberyCreationForm ===" << std::endl;
    try {
        Bureaucrat b("Alice", 137);
        ShrubberyCreationForm f("home");
        std::cout << b << std::endl;
        std::cout << f << std::endl;
        b.signForm(f);
        b.executeForm(f);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Test RobotomyRequestForm ===" << std::endl;
    try {
        Bureaucrat b("Bob", 45);
        RobotomyRequestForm f("Bender");
        b.signForm(f);
        b.executeForm(f);
        b.executeForm(f);
        b.executeForm(f);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Test PresidentialPardonForm ===" << std::endl;
    try {
        Bureaucrat b("Charlie", 5);
        PresidentialPardonForm f("Ford Prefect");
        b.signForm(f);
        b.executeForm(f);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Test execute without signing ===" << std::endl;
    try {
        Bureaucrat b("Dave", 1);
        ShrubberyCreationForm f("garden");
        b.executeForm(f);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Test grade too low to execute ===" << std::endl;
    try {
        Bureaucrat signer("Eve", 1);
        Bureaucrat exec("Frank", 138);
        ShrubberyCreationForm f("park");
        signer.signForm(f);
        exec.executeForm(f);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
