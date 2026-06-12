#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cctype>
#include <limits>
#include <cerrno>

enum e_type
{
	CHAR_LITERAL,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	FLOAT_PSEUDO,
	DOUBLE_PSEUDO,
	INVALID
};

static e_type _detectType(const std::string& s)
{
	if (s.length() == 0)
		return INVALID;

	if (s == "nanf" || s == "+inff" || s == "-inff")
		return FLOAT_PSEUDO;
	if (s == "nan" || s == "+inf" || s == "-inf")
		return DOUBLE_PSEUDO;

	if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
		return CHAR_LITERAL;

	if (s.length() == 1 && std::isprint(static_cast<unsigned char>(s[0]))
		&& !std::isdigit(static_cast<unsigned char>(s[0]))
		&& s[0] != '+' && s[0] != '-' && s[0] != '.')
		return CHAR;

	size_t i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	size_t start = i;

	if (i >= s.length())
		return INVALID;

	bool hasDot = false;
	bool hasDigit = false;

	for (; i < s.length(); i++)
	{
		if (s[i] == '.')
		{
			if (hasDot)
				return INVALID;
			hasDot = true;
		}
		else if (std::isdigit(static_cast<unsigned char>(s[i])))
			hasDigit = true;
		else
			break;
	}

	if (!hasDigit)
		return INVALID;

	if (i == s.length() - 1 && s[i] == 'f')
	{
		if (i == start)
			return INVALID;
		return FLOAT;
	}

	if (i != s.length())
		return INVALID;

	if (hasDot)
		return DOUBLE;

	if (s.length() > 11)
		return INVALID;

	return INT;
}

static void _printChar(double val)
{
	if (std::isnan(val) || std::isinf(val))
		std::cout << "char: impossible" << std::endl;
	else if (val < 0 || val > 127 || !std::isprint(static_cast<int>(val)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
}

static void _printInt(double val)
{
	if (std::isnan(val) || std::isinf(val))
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	if (val < static_cast<double>(INT_MIN) || val > static_cast<double>(INT_MAX))
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	std::cout << "int: " << static_cast<int>(val) << std::endl;
}

static void _printFloat(double val)
{
	std::cout << "float: ";
	if (std::isnan(val))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(val))
	{
		if (val > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	}
	else
	{
		std::cout.precision(1);
		std::cout << std::fixed << val << "f" << std::endl;
	}
}

static void _printDouble(double val)
{
	std::cout << "double: ";
	if (std::isnan(val))
		std::cout << "nan" << std::endl;
	else if (std::isinf(val))
	{
		if (val > 0)
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	}
	else
	{
		std::cout.precision(1);
		std::cout << std::fixed << val << std::endl;
	}
}

void ScalarConverter::convert(const std::string& literal)
{
	e_type type = _detectType(literal);
	double value = 0.0;

	switch (type)
	{
		case CHAR_LITERAL:
			value = static_cast<double>(literal[1]);
			break;
		case CHAR:
			value = static_cast<double>(literal[0]);
			break;
		case INT:
		{
			errno = 0;
			char* end;
			long val = std::strtol(literal.c_str(), &end, 10);
			if (errno == ERANGE || val < INT_MIN || val > INT_MAX)
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				return;
			}
			value = static_cast<double>(val);
			break;
		}
		case FLOAT:
		{
			errno = 0;
			char* end;
			float val = std::strtof(literal.c_str(), &end);
			if (errno == ERANGE && val == HUGE_VALF)
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				_printFloat(static_cast<double>(val));
				_printDouble(static_cast<double>(val));
				return;
			}
			value = static_cast<double>(val);
			break;
		}
		case DOUBLE:
		{
			errno = 0;
			char* end;
			double val = std::strtod(literal.c_str(), &end);
			if (errno == ERANGE)
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				_printFloat(val);
				_printDouble(val);
				return;
			}
			value = val;
			break;
		}
		case FLOAT_PSEUDO:
			if (literal == "nanf")
			{
				value = std::numeric_limits<float>::quiet_NaN();
			}
			else if (literal == "+inff")
			{
				value = std::numeric_limits<float>::infinity();
			}
			else
			{
				value = -std::numeric_limits<float>::infinity();
			}
			break;
		case DOUBLE_PSEUDO:
			if (literal == "nan")
			{
				value = std::numeric_limits<double>::quiet_NaN();
			}
			else if (literal == "+inf")
			{
				value = std::numeric_limits<double>::infinity();
			}
			else
			{
				value = -std::numeric_limits<double>::infinity();
			}
			break;
		case INVALID:
		default:
			std::cerr << "Error: invalid literal" << std::endl;
			return;
	}

	_printChar(value);
	_printInt(value);
	_printFloat(value);
	_printDouble(value);
}
