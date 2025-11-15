#include "Header.hpp"

std::string strSimplify(std::string str){
    return ((str.length() < 10) ? str : str.substr(0, 9).append("."));
}

PhoneBook::PhoneBook ( void ) {
    _bookSize = 0;
    _front = 0;
}

bool PhoneBook::saveContact( Contact contact ) {
    if (contact.hasEmptyField())
        return (false);
    _phoneBook[_front] = contact;
    _front = (_front + 1) % BOOK_CAPACITY;
    if (_bookSize < BOOK_CAPACITY)
        _bookSize++;
    return (true);
}

void PhoneBook::searchForContact( void ) {
    int index;

    if (_bookSize == 0) {
        std::cout << "Phonebook is empty\n";
        return ;
    }

    displayContactList();

    std::cout << "Enter contact index: ";
    std::cin >> index;
    std::cin.ignore(1000, '\n');
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input\n";
        return ;
    }

    if (index < 0 || index >= _bookSize) {
        std::cout << "Index out of range\n";
        return ;
    }

    _phoneBook[index].displayContactInfo();
}

void PhoneBook::displayContactList( void ) {
    std::cout << "  index   | firstname|  lastname|  nickname\n";
    for (int i = 0; i < _bookSize; i++) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << strSimplify(_phoneBook[i].getFirstName()) << "|";
        std::cout << std::setw(10) << strSimplify(_phoneBook[i].getLastName()) << "|";
        std::cout << std::setw(10) << strSimplify(_phoneBook[i].getNickName());
        std::cout << std::endl;
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
