#include "Header.hpp"

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
        while (true) {
            std::cout << prompts[i];
            std::getline(std::cin, contactInput[i]);
            if (std::cin.fail())
                return (false);
            if (contactInput[i].empty()) {
                std::cout << "can't have an empty field\n";
                continue;
            }
            if (contactInput[i].find_first_not_of(" \t") == std::string::npos) {
                std::cout << "can't have spaces alone in a field\n";
                continue;
            }
            break;
        }
    }
    return (true);
}