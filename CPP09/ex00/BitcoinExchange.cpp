#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _rates(other._rates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        _rates = other._rates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static bool isValidDate(const std::string& date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); i++) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 0 || month < 1 || month > 12 || day < 1)
        return false;

    static const int daysInMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day > daysInMonth[month - 1])
        return false;
    return true;
}

BitcoinExchange::BitcoinExchange(const std::string& dbPath) {
    std::ifstream file(dbPath.c_str());
    if (!file.is_open())
        throw std::runtime_error("could not open database file.");

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;
        std::string date = line.substr(0, comma);
        double rate = std::atof(line.substr(comma + 1).c_str());
        _rates[date] = rate;
    }
}

void BitcoinExchange::processFile(const std::string& inputPath) const {
    std::ifstream file(inputPath.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t sep = line.find('|');
        if (sep == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, sep);
        std::string valueStr = line.substr(sep + 1);

        size_t start = date.find_first_not_of(" \t");
        size_t end = date.find_last_not_of(" \t");
        date = (start == std::string::npos) ? "" : date.substr(start, end - start + 1);

        start = valueStr.find_first_not_of(" \t");
        end = valueStr.find_last_not_of(" \t");
        valueStr = (start == std::string::npos) ? "" : valueStr.substr(start, end - start + 1);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        char* endptr;
        double value = std::strtod(valueStr.c_str(), &endptr);
        if (endptr == valueStr.c_str() || *endptr != '\0') {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
        if (it == _rates.end() || it->first != date) {
            if (it == _rates.begin()) {
                std::cerr << "Error: no matching date in database for => " << date << std::endl;
                continue;
            }
            --it;
        }

        std::cout << date << " => " << valueStr << " = " << (it->second * value) << std::endl;
    }
}
