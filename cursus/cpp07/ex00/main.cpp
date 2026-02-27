#include "whatever.hpp"
#include <iostream>

int main(void)
{
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    return 0;
}

// int main()
// {
//     int a = 1, b = 2;
//     std::string c = "1", d = "2";
//     float e = 3.5f, f = 2.5f;

//     /* Test int */
//     std::cout << "-------------" << std::endl;
//     std::cout << "Test with int" << std::endl;
//     std::cout << "-------------" << std::endl;
//     std::cout << "Small value: " << ::min(a, b) << std::endl;
//     std::cout << "Max value: " << ::max(a, b) << std::endl;
//     std::cout << "Before swaping: a=" << a << ", b=" << b << std::endl;
//     swap(a, b);
//     std::cout << "After swaping: a=" << a << ", b=" << b << std::endl << std::endl;

//     /* Test string */
//     std::cout << "----------------" << std::endl;
//     std::cout << "Test with string" << std::endl;
//     std::cout << "----------------" << std::endl;
//     std::cout << "Small value: \"" << ::min(c, d) << "\"" << std::endl;
//     std::cout << "Max value: \"" << ::max(c, d) << "\"" << std::endl;
//     std::cout << "Before swaping: c=\"" << c << "\", d=\"" << d << "\"" << std::endl;
//     swap(c, d);
//     std::cout << "After swaping: c=\"" << c << "\", d=\"" << d << "\"" << std::endl << std::endl;

//     /* Test float */
//     std::cout << "---------------" << std::endl;
//     std::cout << "Test with float" << std::endl;
//     std::cout << "---------------" << std::endl;
//     std::cout << "Small value: " << ::min(e, f) << std::endl;
//     std::cout << "Max value: " << ::max(e, f) << std::endl;
//     std::cout << "Before swaping: e=" << e << ", f=" << f << std::endl;
//     swap(e, f);
//     std::cout << "After swaping: e=" << e << ", f=" << f << std::endl;

//     return (0);
// }