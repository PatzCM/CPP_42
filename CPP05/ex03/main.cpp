/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:30:00 by palexand          #+#    #+#             */
/*   Updated: 2026/03/17 13:30:00 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    std::cout << _CYAN << "\n=== INTERN CREATES SHRUBBERY FORM ===" << _END << std::endl;
    try {
        Intern someRandomIntern;
        AForm *form;

        form = someRandomIntern.makeForm("shrubbery creation", "garden");

        Bureaucrat bob("Bob", 137);
        std::cout << *form << std::endl;
        bob.signForm(*form);
        bob.executeForm(*form);

        delete form;
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }

    std::cout << _CYAN << "\n=== INTERN CREATES ROBOTOMY FORM ===" << _END << std::endl;
    try {
        Intern someRandomIntern;
        AForm *form;

        form = someRandomIntern.makeForm("robotomy request", "Bender");

        Bureaucrat alice("Alice", 40);
        std::cout << *form << std::endl;
        alice.signForm(*form);
        alice.executeForm(*form);

        delete form;
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }

    std::cout << _CYAN << "\n=== INTERN CREATES PRESIDENTIAL PARDON FORM ===" << _END << std::endl;
    try {
        Intern someRandomIntern;
        AForm *form;

        form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

        Bureaucrat president("President", 1);
        std::cout << *form << std::endl;
        president.signForm(*form);
        president.executeForm(*form);

        delete form;
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }

    std::cout << _CYAN << "\n=== INTERN FAILS TO CREATE UNKNOWN FORM ===" << _END << std::endl;
    try {
        Intern someRandomIntern;
        AForm *form;

        form = someRandomIntern.makeForm("unknown form", "target");
        delete form;
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }

    return 0;
}
