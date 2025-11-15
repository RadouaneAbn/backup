#include "Header.hpp"

int main( void ) {
    PhoneBook phoneBook;
    std::string userInput;
    std::string contactInput[5];

    do {
        std::cout << ">> ";
        std::getline(std::cin, userInput);
        if (std::cin.eof()) {
            std::cout << std::endl;
            break;
        }
        else if (std::cin.fail()) {
            std::cin.ignore(1000, '\n');
            std::cin.clear();
            continue;
        }

        if (userInput.empty()) {
            continue;
        }
        else if (userInput == "EXIT") {
            break;
        }
        else if (userInput == "ADD") {
            if (!getContactInput(contactInput)) {
                std::cout << "Unvalid input\n";
                continue;
            }
            Contact newContact = Contact(
                contactInput[0],
                contactInput[1],
                contactInput[2],
                contactInput[3],
                contactInput[4]
            );
            phoneBook.saveContact(newContact);
        }
        else if (userInput == "SEARCH") {
            phoneBook.searchForContact();
        }

    } while (true);
    return (0);
}