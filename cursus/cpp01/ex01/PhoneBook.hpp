#pragma once

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact _phoneBook[8];
        int _bookSize;
        int _front;
    public:
        PhoneBook ( void );
        void displayContactList( void );
        bool saveContact( Contact contact );
        void searchForContact( void );
};
