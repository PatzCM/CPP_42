/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 21:30:29 by palexand          #+#    #+#             */
/*   Updated: 2026/03/13 20:38:00 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "BUREAUCRAT TESTS" << std::endl;
    try {
        Bureaucrat high("Alice", 1);
        Bureaucrat low("Bob", 150);
        std::cout << high << std::endl;
        std::cout << low << std::endl;
        low.incrementGrade();
        high.decrementGrade();
        std::cout << high << std::endl;
        std::cout << low << std::endl;
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }

    std::cout << "\nFORM TESTS" << std::endl;
    try {
        Bureaucrat signer("Charlie", 10);
        Form f1("TaxForm", 10, 10);
        Form f2("SecretForm", 5, 2);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        signer.signForm(f1);
        signer.signForm(f2);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }

    std::cout << "\nINVALID FORM TEST" << std::endl;
    try {
        Form invalid("Broken", 0, 151);
        std::cout << invalid << std::endl;
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }

    return 0;
}
