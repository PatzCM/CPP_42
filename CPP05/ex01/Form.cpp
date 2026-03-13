/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:35:42 by palexand          #+#    #+#             */
/*   Updated: 2026/03/09 18:43:13 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
    : _name(other._name), _signed(other._signed),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form::~Form() {}

Form &Form::operator=(const Form &other) {
    if (this != &other)
        _signed = other._signed;
    return *this;
}

std::string Form::getName() const { return _name; }

bool Form::getIsSigned() const { return _signed; }

int Form::getGradeToSign() const { return _gradeToSign; }

int Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << form.getName() << ", form signed: "
       << (form.getIsSigned() ? "yes" : "no") << ", grade to sign "
       << form.getGradeToSign() << ", grade to execute "
       << form.getGradeToExecute() << ".";
    return os;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high.";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low.";
}
