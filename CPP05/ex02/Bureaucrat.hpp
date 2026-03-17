/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:30:00 by palexand          #+#    #+#             */
/*   Updated: 2026/03/17 13:30:00 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "colors.hpp"
#include <iostream>
#include <string>

class AForm;

class Bureaucrat {
private:
	const std::string _name;
	int _grade;
	static const int maxGrade = 1;
	static const int minGrade = 150;

public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat& value);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& value);

	std::string const &getName() const;
	int	getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(AForm& form) const;
	void executeForm(AForm const & form) const;

	class	GradeTooHighException : public std::exception {
		virtual const char* what() const throw() {
			return "Grade is too high.";
		}
	};

	class	GradeTooLowException : public std::exception {
		virtual const char* what() const throw() {
			return "Grade is too low.";
		}
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& value);
