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
        std::cout << prompts[i];
        std::getline(std::cin, contactInput[i]);
        // std::cin >> contactInput[i];
        if (std::cin.fail())
            return (false);
    }
    return (true);
}