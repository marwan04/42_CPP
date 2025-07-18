#include "Contact.hpp"
#include <iostream>

const std::string fieldNames[5] = {
    "First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"
};

Contact::Contact() {}

Contact::~Contact() {}

bool Contact::set_contact() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Enter " << fieldNames[i] << ": ";
        std::getline(std::cin, _info[i]);
        if (_info[i].empty()) {
            std::cout << "Field cannot be empty.\n";
            return false;
        }
    }
    return true;
}

static std::string format_field(const std::string& field) {
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return std::string(10 - field.length(), ' ') + field;
}

void Contact::get_contact(int index) const {
    if (index >= 0) {
        std::cout << std::setw(10) << index << "|"
                  << format_field(_info[0]) << "|"
                  << format_field(_info[1]) << "|"
                  << format_field(_info[2]) << "\n";
    } else {
        for (int i = 0; i < 5; ++i)
            std::cout << fieldNames[i] << ": " << _info[i] << "\n";
    }
}
