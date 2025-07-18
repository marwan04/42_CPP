#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD")
            phonebook.set_info();
        else if (command == "SEARCH")
            phonebook.get_info();
        else if (command == "EXIT")
            break ;
        else
            std::cout << "Invalid command. Try again.\n";
    }
    return 0;
}
