#include <iostream>
#include "Contact.hpp"

/**
 * Contact constructor:
 */

Contact::Contact () {
    _firstName = "";
    _lastName = "";
    _nickName = "";
    _phoneNumber = "";
    _darkestSecret = "";
}

Contact::Contact (std::string first_name, std::string last_name, std::string nick_name,
                    std::string phone_number, std::string darkest_secret) {
    _firstName = first_name;
    _lastName = last_name;
    _nickName = nick_name;
    _phoneNumber = phone_number;
    _darkestSecret = darkest_secret;
}

/**
 * Contact getters:
 */

std::string Contact::getFirstName( void ) {
    return (_firstName);
}

std::string Contact::getLastName( void ) {
    return (_lastName);
}

std::string Contact::getNickName( void ) {
    return (_nickName);
}

std::string Contact::getPhoneNumber( void ) {
    return (_phoneNumber);
}

std::string Contact::getDarkestSecret( void ) {
    return (_darkestSecret);
}

/**
 * Other methods
 */

void Contact::displayContactInfo( void ) {
    std::cout << "First name:     " << _firstName << std::endl;
    std::cout << "Last name:      " << _lastName << std::endl;
    std::cout << "Nick name:      " << _nickName << std::endl;
    std::cout << "Phone number:   " << _phoneNumber << std::endl;
    std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}

bool Contact::hasEmptyField( void ) {
    return (_firstName.empty() ||
                _lastName.empty() ||
                _nickName.empty() ||
                _phoneNumber.empty() ||
                _darkestSecret.empty());
}