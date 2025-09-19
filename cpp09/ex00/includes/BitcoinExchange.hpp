#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange {
private:
    std::map<std::string, double> _database;
    
    bool isValidDate(const std::string& date) const;
    bool isValidValue(double value) const;
    bool parseDate(const std::string& date, int& year, int& month, int& day) const;
    bool isLeapYear(int year) const;
    std::string trim(const std::string& str) const;
    double stringToDouble(const std::string& str) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    
    bool loadDatabase(const std::string& filename = "data.csv");
    void processInput(const std::string& filename);
    double getExchangeRate(const std::string& date) const;
};

#endif