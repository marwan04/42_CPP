#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

static bool isPseudoLiteral(const std::string& s) {
    return (s == "nan" || s == "nanf" ||
            s == "+inf" || s == "-inf" ||
            s == "+inff" || s == "-inff");
}

void ScalarConverter::convert(const std::string& literal) {
    std::cout << std::fixed << std::setprecision(1);

    if (isPseudoLiteral(literal)) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        if (literal[literal.size() - 1] == 'f') {
            std::cout << "float: " << literal << "\n";
            std::cout << "double: " << literal.substr(0, literal.size() - 1) << "\n";
        } else {
            std::cout << "float: " << literal << "f\n";
            std::cout << "double: " << literal << "\n";
        }
        return;
    }

    if (literal.size() == 1 && !std::isdigit(literal[0])) {
        char c = literal[0];
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << "f\n";
        std::cout << "double: " << static_cast<double>(c) << "\n";
        return;
    }

    char* endptr = NULL;
    errno = 0;

    long l = std::strtol(literal.c_str(), &endptr, 10);
    if (*endptr == '\0' && errno != ERANGE) {
        if (l >= 32 && l <= 126)
            std::cout << "char: '" << static_cast<char>(l) << "'\n";
        else if (l >= 0 && l <= 127)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: impossible\n";
        std::cout << "int: " << l << "\n";
        std::cout << "float: " << static_cast<float>(l) << "f\n";
        std::cout << "double: " << static_cast<double>(l) << "\n";
        return;
    }

    float f = std::strtof(literal.c_str(), &endptr);
    if (*endptr == 'f' && *(endptr + 1) == '\0') {
        if (f >= 32 && f <= 126)
            std::cout << "char: '" << static_cast<char>(f) << "'\n";
        else if (f >= 0 && f <= 127)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: impossible\n";
        std::cout << "int: " << static_cast<int>(f) << "\n";
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << static_cast<double>(f) << "\n";
        return;
    }

    double d = std::strtod(literal.c_str(), &endptr);
    if (*endptr == '\0') {
        if (d >= 32 && d <= 126)
            std::cout << "char: '" << static_cast<char>(d) << "'\n";
        else if (d >= 0 && d <= 127)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: impossible\n";
        std::cout << "int: " << static_cast<int>(d) << "\n";
        std::cout << "float: " << static_cast<float>(d) << "f\n";
        std::cout << "double: " << d << "\n";
        return;
    }

    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}
