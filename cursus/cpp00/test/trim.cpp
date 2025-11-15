#include <iostream>

void ltrim(std::string& str) {
    // std::cout << str.find_first_not_of(' ') << std::endl;
    str.erase(0, str.find_first_not_of(' '));
}

void rtrim(std::string& str) {
    // std::cout << str.find_last_not_of(' ') << std::endl;
    str.erase(str.find_last_not_of(' ') + 1, str.size());
}


int main(int ac, char *av[]) {
    std::string str;
    if (ac == 2) {
        str = av[1];
        std::cout << "1: '" << str << "'" << std::endl;
        ltrim(str);
        rtrim(str);
        std::cout << "1: '" << str << "'" << std::endl;
    }
}

// int main ()
// {
//   std::string str ("This is an example sentence.");
//   std::cout << str << '\n';
//                                            // "This is an example sentence."
//   str.erase (10,8);                        //            ^^^^^^^^
//   std::cout << str << '\n';
//                                            // "This is an sentence."
//   str.erase (str.begin()+9);               //           ^
//   std::cout << str << '\n';
//                                            // "This is a sentence."
//   str.erase (str.begin()+5, str.end()-9);  //       ^^^^^
//   std::cout << str << '\n';
//                                            // "This sentence."
//   return 0;
// }