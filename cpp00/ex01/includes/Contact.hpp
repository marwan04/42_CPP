#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iomanip>
#include <cstdlib>
#include <iostream>

class Contact
{
    private:
        std::string         _info[5];

        enum Field
        {
            FirstName = 0,
            LastName,
            NickName,
            PhoneNumber,
            Secret
        };
    
    public:
        Contact(void);
        ~Contact(void);
        
        bool set_contact();
        void get_contact(int index)const;
};
#endif