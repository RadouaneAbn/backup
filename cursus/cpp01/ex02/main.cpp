#include <iostream>

int main ( void ) {
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string& stringREF = string;

    std::cout << "string addr:    " << &string << std::endl;
    std::cout << "stringPTR addr: " << &stringPTR << std::endl;
    std::cout << "stringREF addr: " << &stringREF << std::endl;

    std::cout << string << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
}