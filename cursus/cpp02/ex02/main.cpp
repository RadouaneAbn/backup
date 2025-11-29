#include "Fixed.hpp"

std::ostream& operator<<(std::ostream &out, const Fixed &value) {
    out << value.toFloat();
    return out;
}

int main() {
    Fixed a(10.2f);
    Fixed b(10.1f);
    Fixed c( a );
    Fixed d;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;

    std::cout << "(a > c) -> " << ((a > c) ? "true" : "false") << std::endl;
    std::cout << "(a < b) -> " << ((a < b) ? "true" : "false") << std::endl;
    std::cout << "(a <= b) -> " << ((a <= b) ? "true" : "false") << std::endl;
    std::cout << "(a >= c) -> " << ((a >= c) ? "true" : "false") << std::endl;
    
    std::cout << "(a == c) -> " << ((a == c) ? "true" : "false") << std::endl;
    std::cout << "(a == b) -> " << ((a == b) ? "true" : "false") << std::endl;
    std::cout << "(a != b) -> " << ((a != b) ? "true" : "false") << std::endl;
    std::cout << "(a != c) -> " << ((a != c) ? "true" : "false") << std::endl;

    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl;

    a++;
    std::cout << "a++ = " << a  << std::endl;
    b--;
    std::cout << "b-- = " << b  << std::endl;

    std::cout << "--a = " << --a << std::endl;
    std::cout << "++b = " << ++b << std::endl;

    std::cout << "d = " << d << std::endl;
    d++;
    std::cout << "d++" << std::endl << "d = " << d << std::endl;

    return (0);
}

// int main( void ) {
//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;
//     return 0;
// }
