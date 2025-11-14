#include <iostream>
#include "PhoneBook.hpp"

void create_new_contact(void) {
    Contact newContact;
    std::string input[5];
    std::string inputMsgs[] = {
        "First name     : ",
        "Last name      : ",
        "Nick name      : ",
        "Phone number   : ",
        "Darkest secret : ",
    };

    for (int i = 0; i < 5; i++) {
        std::cout << inputMsgs[i];
        std::cin >> input[i];
        if (std::cin.fail() || ) {
            std::cin.ignore(1000, '\n');
            std::cin.clear();
            return ;
        }
    }


}

int main(void) {
    std::string inputCmd;

    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

    do {
        std::cout << ">> ";
        std::getline(std::cin, inputCmd);
        if (std::cin.eof())
            break;
        if (inputCmd == "")
            continue;
        if (inputCmd == "ADD") {
            std::cout << "add number to stack" << std::endl;
            create_new_contact();
        } else if (inputCmd == "SEARCH") {
            std::cout << "search for number in stack" << std::endl; 
        } else if (inputCmd == "EXIT") {
            std::cout << "exiting" << std::endl;
            break;
        } else
            std::cout << "command not found" << std::endl;
    }
    while (true);
    
}