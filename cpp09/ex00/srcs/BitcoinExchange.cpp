#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string& str) const {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::parseDate(const std::string& date, int& year, int& month, int& day) const {
    if (date.length() != 10)
        return false;
    
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
    
    // Check if all characters are digits
    for (size_t i = 0; i < yearStr.length(); i++) {
        if (!std::isdigit(yearStr[i]))
            return false;
    }
    for (size_t i = 0; i < monthStr.length(); i++) {
        if (!std::isdigit(monthStr[i]))
            return false;
    }
    for (size_t i = 0; i < dayStr.length(); i++) {
        if (!std::isdigit(dayStr[i]))
            return false;
    }
    
    std::istringstream yearStream(yearStr);
    std::istringstream monthStream(monthStr);
    std::istringstream dayStream(dayStr);
    
    yearStream >> year;
    monthStream >> month;
    dayStream >> day;
    
    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    int year, month, day;
    
    if (!parseDate(date, year, month, day))
        return false;
    
    // Check year range (reasonable range for bitcoin - Bitcoin was created in 2009)
    if (year < 2009 || year > 2030)
        return false;
    
    // Check month range
    if (month < 1 || month > 12)
        return false;
    
    // Days in month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Adjust for leap year
    if (isLeapYear(year))
        daysInMonth[1] = 29;
    
    // Check day range
    if (day < 1 || day > daysInMonth[month - 1])
        return false;
    
    return true;
}

bool BitcoinExchange::isValidValue(double value) const {
    return value >= 0 && value <= 1000;
}

double BitcoinExchange::stringToDouble(const std::string& str) const {
    std::istringstream iss(str);
    double result;
    
    iss >> result;
    
    // Check if conversion failed or there are remaining characters
    if (iss.fail() || !iss.eof())
        throw std::invalid_argument("Invalid number format");
    
    return result;
}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return false;
    }
    
    std::string line;
    bool firstLine = true;
    
    while (std::getline(file, line)) {
        // Skip header line
        if (firstLine) {
            firstLine = false;
            continue;
        }
        
        if (line.empty())
            continue;
        
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
            continue;
        
        std::string date = trim(line.substr(0, commaPos));
        std::string valueStr = trim(line.substr(commaPos + 1));
        
        try {
            double value = stringToDouble(valueStr);
            if (isValidDate(date)) {
                _database[date] = value;
            }
        } catch (const std::exception& e) {
            // Skip invalid entries in database
            continue;
        }
    }
    
    file.close();
    return !_database.empty();
}

double BitcoinExchange::getExchangeRate(const std::string& date) const {
    // Find the exact date or the closest lower date
    std::map<std::string, double>::const_iterator it = _database.upper_bound(date);
    
    if (it == _database.begin()) {
        // Date is before all dates in database
        return _database.begin()->second;
    }
    
    --it; // Get the previous element (closest lower date)
    return it->second;
}

void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    bool firstLine = true;
    
    while (std::getline(file, line)) {
        // Skip header line
        if (firstLine) {
            firstLine = false;
            continue;
        }
        
        if (line.empty())
            continue;
        
        size_t pipePos = line.find('|');
        size_t commaPos = line.find(',');
        size_t separatorPos;
        
        // Check for pipe separator first (preferred format)
        if (pipePos != std::string::npos) {
            separatorPos = pipePos;
        }
        // Fall back to comma separator if no pipe found
        else if (commaPos != std::string::npos) {
            separatorPos = commaPos;
        }
        // No valid separator found
        else {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = trim(line.substr(0, separatorPos));
        std::string valueStr = trim(line.substr(separatorPos + 1));
        
        // Validate date format
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        // Validate and convert value
        double value;
        try {
            value = stringToDouble(valueStr);
        } catch (const std::exception& e) {
            std::cerr << "Error: bad input => " << valueStr << std::endl;
            continue;
        }
        
        // Check value range
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        
        // Calculate and display result
        double rate = getExchangeRate(date);
        double result = value * rate;
        
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    
    file.close();
}