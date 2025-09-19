#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    try {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);

        std::cout << "Vector test:" << std::endl;
        std::cout << "Found: " << *easyfind(vec, 20) << std::endl;
        std::cout << "Found: " << *easyfind(vec, 30) << std::endl;
        std::cout << "Found: " << *easyfind(vec, 50) << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);

        std::cout << "\nList test:" << std::endl;
        std::cout << "Found: " << *easyfind(lst, 2) << std::endl;
        std::cout << "Found: " << *easyfind(lst, 1) << std::endl;
        std::cout << "Found: " << *easyfind(lst, 99) << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
