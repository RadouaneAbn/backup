#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <exception>

int do_math(char *s);

class WrongInput : public std::exception
{
    virtual const char *what(void) const throw()
    {
        return "Wrong input";
    }
};

#endif