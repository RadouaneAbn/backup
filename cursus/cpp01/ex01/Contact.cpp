#include <iostream>
#include "Contact.hpp"

/**
 * Contact constructor:
 */

Contact::Contact () {
    firstName = "";
    lastName = "";
    nickName = "";
    phoneNumber = "";
    darkestSecret = "";
}

Contact::Contact (std::string first_name, std::string last_name, std::string nick_name,
                    std::string phone_number, std::string darkest_secret) {
    firstName = first_name;
    lastName = last_name;
    nickName = nick_name;
    phoneNumber = phone_number;
    darkestSecret = darkest_secret;
}

/**
 * Contact getters:
 */

std::string Contact::getFirstName( void ) {
    return (firstName);
}

std::string Contact::getLastName( void ) {
    return (lastName);
}

std::string Contact::getNickName( void ) {
    return (nickName);
}

std::string Contact::getPhoneNumber( void ) {
    return (phoneNumber);
}

std::string Contact::getDarkestSecret( void ) {
    return (darkestSecret);
}

/**
 * Other methods
 */

bool Contact::hasEmptyField( void ) {
    return (firstName.empty() ||
                lastName.empty() ||
                nickName.empty() ||
                phoneNumber.empty() ||
                darkestSecret.empty());
}