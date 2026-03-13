/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 21:23:37 by palexand          #+#    #+#             */
/*   Updated: 2026/03/06 21:29:55 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
		if (grade < maxGrade)
				throw GradeTooHighException();
		else if (grade > minGrade)
				throw GradeTooLowException();
		else
				_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& value) : _name(value._name), _grade(value._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& value) {
	const_cast<std::string&>(_name) = value._name;
	_grade = value._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade <= 1)
			throw GradeTooHighException();
		_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(class Form& form) const {
	try {
		form.beSigned(*this);
		std::cout << _GREEN << getName() << " signed " << form.getName() << _END
							<< std::endl;
	} catch (std::exception &e) {
		std::cout << _RED << getName() << " couldn't sign " << form.getName()
							<< " because " << e.what() << _END << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& value) {
	os << value.getName() << ", bureaucrat grade " << value.getGrade() << ".";
	return os;
}
