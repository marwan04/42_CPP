#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span(unsigned int N);
    ~Span();

    Span(const Span& other);
    Span& operator=(const Span& other);

    void addNumber(int num);

    template <typename It>
    void addNumber(It begin, It end) {
        if (_numbers.size() + std::distance(begin, end) > _maxSize)
            throw std::runtime_error("Adding range exceeds Span capacity");
        _numbers.insert(_numbers.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;
};

#endif
