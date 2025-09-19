#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <cmath>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);

public:
    ~ScalarConverter();

    static void convert(const std::string& literal);
};

#endif
