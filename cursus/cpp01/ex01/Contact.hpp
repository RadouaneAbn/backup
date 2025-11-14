#pragma once

#include <iostream>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        Contact();
        Contact (std::string first_name, std::string last_name, std::string nick_name,
                    std::string phone_number, std::string darkest_secret);
        std::string getFirstName( void );
        std::string getLastName( void );
        std::string getNickName( void );
        std::string getPhoneNumber( void );
        std::string getDarkestSecret( void );
        bool hasEmptyField( void );
};
