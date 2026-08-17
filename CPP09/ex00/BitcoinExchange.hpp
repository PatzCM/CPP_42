#pragma once

#include <map>
#include <string>

class BitcoinExchange {
private:
    std::map<std::string, double> _rates;

public:
    BitcoinExchange();
    BitcoinExchange(const std::string& dbPath);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void processFile(const std::string& inputPath) const;
};
