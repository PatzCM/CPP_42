/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:30:00 by palexand          #+#    #+#             */
/*   Updated: 2026/03/17 13:30:00 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target) {
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm *forms[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            for (int j = 0; j < 3; j++) {
                if (i != j)
                    delete forms[j];
            }
            return forms[i];
        }
    }

    for (int i = 0; i < 3; i++)
        delete forms[i];

    throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
    return "Form not found.";
}
