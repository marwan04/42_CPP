#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <ctime>
#include <sys/time.h>
#include <algorithm>
#include <iterator>

class PmergeMe {
private:
    std::vector<int> _vectorData;
    std::deque<int> _dequeData;

    std::vector<int> generateJacobsthalSequence(int n) const;
    void mergeInsertSortVector(std::vector<int>& arr);
    void mergeInsertSortDeque(std::deque<int>& arr);

    std::vector<int>::iterator binaryInsertVector(std::vector<int>& arr, 
                                                  std::vector<int>::iterator begin, 
                                                  std::vector<int>::iterator end, 
                                                  int value);
    std::deque<int>::iterator binaryInsertDeque(std::deque<int>& arr, 
                                                std::deque<int>::iterator begin, 
                                                std::deque<int>::iterator end, 
                                                int value);

    double getTimeInMicroseconds() const;

    bool isValidPositiveInteger(const std::string& str) const;
    void validateInput(int argc, char** argv);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    void parseAndSort(int argc, char** argv);
    void displayResults() const;
};

#endif