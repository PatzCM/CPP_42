#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("Cannot open file");

    file << "       _-_       " << std::endl;
    file << "    /~~   ~~\\    " << std::endl;
    file << " /~~         ~~\\ " << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  / " << std::endl;
    file << "   ~  \\ //  ~   " << std::endl;
    file << "_- -   | | _- _  " << std::endl;
    file << "  _ -  | |   -_  " << std::endl;
    file << "      // \\\\      " << std::endl;
}
