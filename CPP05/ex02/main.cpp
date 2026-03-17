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

int main() {
    std::cout << _CYAN << "\n=== SHRUBBERY CREATION FORM TEST ===" << _END << std::endl;
    try {
        Bureaucrat bob("Bob", 137);
        ShrubberyCreationForm shrub("home");

        std::cout << bob << std::endl;
        std::cout << shrub << std::endl;

        bob.signForm(shrub);
        bob.executeForm(shrub);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }

    std::cout << _CYAN << "\n=== ROBOTOMY REQUEST FORM TEST ===" << _END << std::endl;
    try {
        Bureaucrat alice("Alice", 40);
        RobotomyRequestForm robot("Bender");

        std::cout << alice << std::endl;
        std::cout << robot << std::endl;

        alice.signForm(robot);
        alice.executeForm(robot);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }

    std::cout << _CYAN << "\n=== PRESIDENTIAL PARDON FORM TEST ===" << _END << std::endl;
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << president << std::endl;
        std::cout << pardon << std::endl;

        president.signForm(pardon);
        president.executeForm(pardon);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }

    std::cout << _CYAN << "\n=== FAILURE TEST: FORM NOT SIGNED ===" << _END << std::endl;
    try {
        Bureaucrat lowly("Lowly", 150);
        ShrubberyCreationForm shrub2("garden");

        lowly.executeForm(shrub2);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }

    std::cout << _CYAN << "\n=== FAILURE TEST: GRADE TOO LOW TO SIGN ===" << _END << std::endl;
    try {
        Bureaucrat lowly("Lowly", 150);
        PresidentialPardonForm pardon2("Criminal");

        lowly.signForm(pardon2);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }

    std::cout << _CYAN << "\n=== FAILURE TEST: GRADE TOO LOW TO EXECUTE ===" << _END << std::endl;
    try {
        Bureaucrat signer("Signer", 25);
        Bureaucrat executor("Executor", 10);
        PresidentialPardonForm pardon3("Prisoner");

        signer.signForm(pardon3);
        executor.executeForm(pardon3);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }

    return 0;
}
