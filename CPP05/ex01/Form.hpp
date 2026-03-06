#pragma once

#include <string>

class Form {
private:
		const std::string _name;
		bool _signed;
		const int gradeToSign;
		const int gradeToExecute;
public:
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
}
