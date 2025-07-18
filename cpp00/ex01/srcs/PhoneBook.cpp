#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : _index(0), _full(false) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::set_info() {
    if (_contacts[_index].set_contact()) {
        _index = (_index + 1) % 8;
        if (_index == 0)
            _full = true;
    }
}

void PhoneBook::get_info() {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "\n";
    
    int max = _full ? 8 : _index;
    for (int i = 0; i < max; i++)
        _contacts[i].get_contact(i);

    std::string input;
    std::cout << "Enter index to view details: ";
    std::getline(std::cin, input);
    int idx = std::atoi(input.c_str());

    if (idx >= 0 && idx < max)
        _contacts[idx].get_contact(-1);
    else
        std::cout << "Invalid index.\n";
}
