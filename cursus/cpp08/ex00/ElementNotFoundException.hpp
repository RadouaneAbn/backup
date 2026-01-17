#ifndef ELEMENTNOTFOUNDEXCEPTION_HPP
#define ELEMENTNOTFOUNDEXCEPTION_HPP

#include <exception>

class ElementNotFoundException : public std::exception {
public:
    const char* what() const throw() {
        return "Element not found in the container.";
    }
};


#endif 