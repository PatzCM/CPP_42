/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:30:00 by palexand          #+#    #+#             */
/*   Updated: 2026/03/17 13:30:00 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), _signed(other._signed),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other)
        _signed = other._signed;
    return *this;
}

std::string AForm::getName() const { return _name; }

bool AForm::getIsSigned() const { return _signed; }

int AForm::getGradeToSign() const { return _gradeToSign; }

int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _signed = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << form.getName() << ", form signed: "
       << (form.getIsSigned() ? "yes" : "no") << ", grade to sign "
       << form.getGradeToSign() << ", grade to execute "
       << form.getGradeToExecute() << ".";
    return os;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high.";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low.";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed.";
}
