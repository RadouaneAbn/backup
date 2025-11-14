#include "PhoneBook.hpp"
#include <iomanip>

std::string strSimplify(std::string str){
    return ((str.length() < 10) ? str : str.substr(0, 9).append("."));
}

PhoneBook::PhoneBook ( void ) {
    _bookCapacity = 8;
    _bookSize = 0;
    _front = 0;
}

bool PhoneBook::saveContact( Contact contact ) {
    if (contact.hasEmptyField())
        return (false);
    _phoneBook[_front] = contact;
    _front = (_front + 1) % _bookCapacity;
    if (_bookSize < 8)
        _bookSize++;
    return (true);
}

void PhoneBook::searchForContact( void ) {
    displayContactList();
}

void PhoneBook::displayContactList( void ) {
    if (_bookSize == 0) {
        std::cout << "Phonebook is empty\n";
        return ;
    }
    std::cout << "|  index   | firstname|  lastname|  nickname|\n";
    for (int i = 0; i < _bookSize; i++) {
        std::cout << "|" << std::setw(10) << i << "|";
        std::cout << std::setw(10) << strSimplify(_phoneBook[i].getFirstName()) << "|";
        std::cout << std::setw(10) << strSimplify(_phoneBook[i].getLastName()) << "|";
        std::cout << std::setw(10) << strSimplify(_phoneBook[i].getNickName());
        std::cout << "|" << std::endl;
    }
}

// 111111111111
// 222222222222
// 333333333333
// 444444444444
// 555555555555
// 666666666666
// 777777777777
// 888888888888
// 999999999999
