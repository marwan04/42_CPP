#include <iostream>
#include <vector>
#include "Span.hpp"

int main() {
    try {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Test with bulk add
        Span bigSpan(10000);
        std::vector<int> vec;
        for (int i = 0; i < 10000; i++) vec.push_back(i * 2);

        bigSpan.addNumber(vec.begin(), vec.end());

        std::cout << "Big span shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Big span longest: " << bigSpan.longestSpan() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
