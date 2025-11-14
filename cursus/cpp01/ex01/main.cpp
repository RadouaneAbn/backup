#include "PhoneBook.hpp"

bool getContactInput( std::string contactInput[5] ) {
    std::string prompts[] = {
        "first name     : ",
        "last name      : ",
        "nick name      : ",
        "phone number   : ",
        "darkest secret : "
    };
    std::string tmpInput;

    for (int i = 0; i < 5; i++) {
        std::cout << prompts[i];
        std::cin >> contactInput[i];
        if (std::cin.fail())
            return (false);
    }
    return (true);
}

int main( void ) {
    PhoneBook phoneBook;
    std::string userInput;
    std::string contactInput[5];

    do {
        std::cout << ">> ";
        std::cin >> userInput;
        if (std::cin.eof()) {
            break;
        }
        else if (std::cin.fail()) {
            std::cin.ignore(1000, '\n');
            std::cin.clear();
            continue;
        }

        if (userInput == "EXIT") {
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
            // std::cout << "New Contact: " << &(newContact) << std::endl;
            phoneBook.saveContact(newContact);
        }
        else if (userInput == "SEARCH") {
            phoneBook.searchForContact();
        }

    } while (true);
    std::cout << std::endl;
    return (0);
}