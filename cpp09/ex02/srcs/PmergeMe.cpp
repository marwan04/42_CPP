#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) 
    : _vectorData(other._vectorData), _dequeData(other._dequeData) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

double PmergeMe::getTimeInMicroseconds() const {
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000000.0) + time.tv_usec;
}

bool PmergeMe::isValidPositiveInteger(const std::string& str) const {
    if (str.empty())
        return false;

    size_t start = 0;
    if (str[0] == '+') {
        start = 1;
    } else if (str[0] == '-') {
        return false;
    }
    
    if (start >= str.length())
        return false;

    for (size_t i = start; i < str.length(); i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    
    std::istringstream iss(str);
    long long num;
    iss >> num;
    
    return num >= 0 && num <= INT_MAX;
}

void PmergeMe::validateInput(int argc, char** argv) {
    if (argc < 2) {
        throw std::runtime_error("Error: No arguments provided");
    }
    
    for (int i = 1; i < argc; i++) {
        if (!isValidPositiveInteger(argv[i])) {
            throw std::runtime_error("Error: Invalid input");
        }
    }
}

std::vector<int> PmergeMe::generateJacobsthalSequence(int n) const {
    std::vector<int> jacobsthal;
    if (n <= 0) return jacobsthal;

    jacobsthal.push_back(0);
    if (n > 1) jacobsthal.push_back(1);
    
    int prev2 = 0, prev1 = 1;
    while (true) {
        int next = prev1 + 2 * prev2;
        if (next > n) break;
        jacobsthal.push_back(next);
        prev2 = prev1;
        prev1 = next;
    }
    
    return jacobsthal;
}

std::vector<int>::iterator PmergeMe::binaryInsertVector(std::vector<int>& arr, 
                                                        std::vector<int>::iterator begin, 
                                                        std::vector<int>::iterator end, 
                                                        int value) {
    std::vector<int>::iterator pos = std::lower_bound(begin, end, value);
    return arr.insert(pos, value);
}

std::deque<int>::iterator PmergeMe::binaryInsertDeque(std::deque<int>& arr, 
                                                      std::deque<int>::iterator begin, 
                                                      std::deque<int>::iterator end, 
                                                      int value) {
    std::deque<int>::iterator pos = std::lower_bound(begin, end, value);
    return arr.insert(pos, value);
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr) {
    if (arr.size() <= 1) return;

    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = (arr.size() % 2 == 1);
    int straggler = hasStraggler ? arr.back() : 0;
    
    for (size_t i = 0; i < arr.size() - (hasStraggler ? 1 : 0); i += 2) {
        int a = arr[i];
        int b = arr[i + 1];
        if (a > b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    if (pairs.size() > 1) {
        std::vector<int> largerElements;
        for (size_t i = 0; i < pairs.size(); i++) {
            largerElements.push_back(pairs[i].second);
        }
        mergeInsertSortVector(largerElements);

        std::vector<std::pair<int, int> > sortedPairs;
        for (size_t i = 0; i < largerElements.size(); i++) {
            for (size_t j = 0; j < pairs.size(); j++) {
                if (pairs[j].second == largerElements[i]) {
                    sortedPairs.push_back(pairs[j]);
                    break;
                }
            }
        }
        pairs = sortedPairs;
    }

    std::vector<int> mainChain;
    std::vector<int> pending;
    
    if (!pairs.empty()) {
        mainChain.push_back(pairs[0].first);  
        mainChain.push_back(pairs[0].second); 
        
        for (size_t i = 1; i < pairs.size(); i++) {
            mainChain.push_back(pairs[i].second); 
            pending.push_back(pairs[i].first);    
        }
    }

    std::vector<int> jacobsthal = generateJacobsthalSequence(pending.size());
    std::vector<bool> inserted(pending.size(), false);
    
    for (size_t i = 0; i < jacobsthal.size(); i++) {
        int idx = jacobsthal[i];
        if (idx > 0 && idx <= static_cast<int>(pending.size()) && !inserted[idx - 1]) {
            binaryInsertVector(mainChain, mainChain.begin(), mainChain.end(), pending[idx - 1]);
            inserted[idx - 1] = true;
        }
    }

    for (size_t i = 0; i < pending.size(); i++) {
        if (!inserted[i]) {
            binaryInsertVector(mainChain, mainChain.begin(), mainChain.end(), pending[i]);
        }
    }

    if (hasStraggler) {
        binaryInsertVector(mainChain, mainChain.begin(), mainChain.end(), straggler);
    }
    
    arr = mainChain;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = (arr.size() % 2 == 1);
    int straggler = hasStraggler ? arr.back() : 0;
    
    for (size_t i = 0; i < arr.size() - (hasStraggler ? 1 : 0); i += 2) {
        int a = arr[i];
        int b = arr[i + 1];
        if (a > b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    if (pairs.size() > 1) {
        std::deque<int> largerElements;
        for (size_t i = 0; i < pairs.size(); i++) {
            largerElements.push_back(pairs[i].second);
        }
        mergeInsertSortDeque(largerElements);

        std::vector<std::pair<int, int> > sortedPairs;
        for (size_t i = 0; i < largerElements.size(); i++) {
            for (size_t j = 0; j < pairs.size(); j++) {
                if (pairs[j].second == largerElements[i]) {
                    sortedPairs.push_back(pairs[j]);
                    break;
                }
            }
        }
        pairs = sortedPairs;
    }

    std::deque<int> mainChain;
    std::vector<int> pending;
    
    if (!pairs.empty()) {
        mainChain.push_back(pairs[0].first);  
        mainChain.push_back(pairs[0].second); 
        
        for (size_t i = 1; i < pairs.size(); i++) {
            mainChain.push_back(pairs[i].second); 
            pending.push_back(pairs[i].first);    
        }
    }

    std::vector<int> jacobsthal = generateJacobsthalSequence(pending.size());
    std::vector<bool> inserted(pending.size(), false);
    
    for (size_t i = 0; i < jacobsthal.size(); i++) {
        int idx = jacobsthal[i];
        if (idx > 0 && idx <= static_cast<int>(pending.size()) && !inserted[idx - 1]) {
            binaryInsertDeque(mainChain, mainChain.begin(), mainChain.end(), pending[idx - 1]);
            inserted[idx - 1] = true;
        }
    }

    for (size_t i = 0; i < pending.size(); i++) {
        if (!inserted[i]) {
            binaryInsertDeque(mainChain, mainChain.begin(), mainChain.end(), pending[i]);
        }
    }

    if (hasStraggler) {
        binaryInsertDeque(mainChain, mainChain.begin(), mainChain.end(), straggler);
    }
    
    arr = mainChain;
}

void PmergeMe::parseAndSort(int argc, char** argv) {
    validateInput(argc, argv);

    for (int i = 1; i < argc; i++) {
        int value = std::atoi(argv[i]);
        _vectorData.push_back(value);
        _dequeData.push_back(value);
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < _vectorData.size(); i++) {
        std::cout << _vectorData[i];
        if (i < _vectorData.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;

    double startTime = getTimeInMicroseconds();
    mergeInsertSortVector(_vectorData);
    double endTime = getTimeInMicroseconds();
    double vectorTime = endTime - startTime;

    startTime = getTimeInMicroseconds();
    mergeInsertSortDeque(_dequeData);
    endTime = getTimeInMicroseconds();
    double dequeTime = endTime - startTime;

    std::cout << "After:  ";
    for (size_t i = 0; i < _vectorData.size(); i++) {
        std::cout << _vectorData[i];
        if (i < _vectorData.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << _vectorData.size() 
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _dequeData.size() 
              << " elements with std::deque : " << dequeTime << " us" << std::endl;
}
