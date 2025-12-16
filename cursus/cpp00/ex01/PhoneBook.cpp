#include "Header.hpp"

std::string strSimplify(std::string str) {
    return ((str.length() < 10) ? str : str.substr(0, 9).append("."));
}

bool strIsNumbers(std::string &str) {
    for (int i = 0; str[i]; i++) {
        if (!std::isdigit(str[i]))
            return (false);
    }
    return (true);
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
    std::string inputIndex;
    int index;

    if (_bookSize == 0) {
        std::cout << "Phonebook is empty\n";
        return ;
    }

    displayContactList();

    std::cout << "Enter contact index: ";
    std::getline(std::cin, inputIndex);
    if (std::cin.eof()) {
        std::cout << std::endl;
        return ;
    }
    if (std::cin.fail()) {
        std::cin.ignore(1000, '\n');
        std::cin.clear();
        std::cout << "Invalid input\n";
        return ;
    }
    else if (!strIsNumbers(inputIndex)) {
        std::cout << "Invalid input\n";
        return ;
    }
    index = std::atoi(inputIndex.c_str());
    if (index < 0 || index >= _bookSize) {
        std::cout << "Index out of range\n";
        return ;
    }

    _phoneBook[index].displayContactInfo();
}

void PhoneBook::displayContactList( void ) {
    std::cout << "     index| firstname|  lastname|  nickname\n";
    for (int i = 0; i < _bookSize; i++) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << strSimplify(_phoneBook[i].getFirstName()) << "|";
        std::cout << std::setw(10) << strSimplify(_phoneBook[i].getLastName()) << "|";
        std::cout << std::setw(10) << strSimplify(_phoneBook[i].getNickName());
        std::cout << std::endl;
    }
}
