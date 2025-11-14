#include <iostream>
#include "Contact.hpp"


class PhoneBook {
    private:
        Contact* book[8];
        int front;
        int phoneBookSize;

    public:
        PhoneBook () {
            front = 0;
            phoneBookSize = 8;
        };
        Contact* add(Contact Contact);
        Contact* search(void);
};