#include "String.hpp"

/**
 * Without copy constructor the object been shallow copied
 * which means the object gets a new address but the pointer
 *  members get copied by address which means that string is
 *  now the same for both objects str1 and str2 
 */

int main() {
    String str1 = "hello world";
    String str2 = str1;

    std::cout << "str1 object addr: " << &str1 << std::endl;
    std::cout << "str2 object addr: " << &str2 << std::endl;

    std::cout << "str1 buffer addr: " << static_cast<void*>(str1._buffer) << std::endl;
    std::cout << "str2 buffer addr: " << static_cast<void*>(str2._buffer) << std::endl;

    std::cout << "str1 pointer-member addr: " << &str1._buffer << std::endl;
    std::cout << "str2 pointer-member addr: " << &str2._buffer << std::endl;
}