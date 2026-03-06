/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 21:30:29 by palexand          #+#    #+#             */
/*   Updated: 2026/03/06 21:31:15 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	 std::cout << "Tests with (*) at the begining should print an exception"
              << std::endl
              << std::endl;

    /* ------------------------------------ */

    std::cout << "TEST 1) Using default constructer" << std::endl;
    try {
        Bureaucrat obj;
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "TEST 2) Instanciate with valid values" << std::endl;
    try {
        Bureaucrat obj("John", 10);
    } catch (std::exception &e) {
        std::cout << _RED << "THIS MESSAGE SHOULD NOT PRINT: " << e.what()
                  << _END << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "TEST 3) Instanciate with highest grade valid" << std::endl;
    try {
        Bureaucrat obj("John", 1);
    } catch (std::exception &e) {
        std::cout << _RED << "THIS MESSAGE SHOULD NOT PRINT: " << e.what()
                  << _END << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "TEST 4) Instanciate with lowest grade valid" << std::endl;
    try {
        Bureaucrat obj("John", 150);
    } catch (std::exception &e) {
        std::cout << _RED << "THIS MESSAGE SHOULD NOT PRINT: " << e.what()
                  << _END << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "* TEST 5) Instanciate with grade 0" << std::endl;
    try {
        Bureaucrat obj("John", 0);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "* TEST 6) Instanciate with grade 151" << std::endl;
    try {
        Bureaucrat obj("John", 151);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "TEST 7) Instanciate with grade 1, decrement 2 times and "
                 "increment 2 times"
              << std::endl;
    try {
        Bureaucrat obj("John", 1);
        obj.decrementGrade();
        obj.decrementGrade();
        obj.incrementGrade();
        obj.incrementGrade();
        std::cout << obj << std::endl;
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "TEST 8) Instanciate with grade 150, decrement and increment"
              << std::endl;
    try {
        Bureaucrat obj("John", 150);
        obj.incrementGrade();
        obj.decrementGrade();
        std::cout << obj << std::endl;
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "* TEST 9) Instanciate with grade 150 and decrementGrade"
              << std::endl;
    try {
        Bureaucrat obj("John", 150);
        obj.decrementGrade();
        std::cout << obj << std::endl;
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "* TEST 10) Instanciate with grade 1 and increment"
              << std::endl;
    try {
        Bureaucrat obj("John", 1);
        obj.incrementGrade();
        std::cout << obj << std::endl;
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "* TEST 11) Instanciate with grade 1, instanciate by copy and "
                 "increment"
              << std::endl;
    try {
        Bureaucrat one("John", 1);
        Bureaucrat two(one);
        two.incrementGrade();
        std::cout << one << std::endl;
        std::cout << two << std::endl;
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "* TEST 12) Instanciate with grade 1, assign and increment"
              << std::endl;
    try {
        Bureaucrat one("John", 1);
        Bureaucrat two("Jane", 20);
        std::cout << two << std::endl;
        two = one;
        std::cout << two << std::endl;
        two.incrementGrade();
        std::cout << one << std::endl;
        std::cout << two << std::endl;
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;	return 0;
}
