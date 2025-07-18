#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact _contacts[8];
        int     _index;
        bool    _full;

    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void set_info(void);
        void get_info(void);
        void set_instructions(void);
};

#endif