#include <iostream>

class Contact {

    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    
    public:

        std::string& get_firstname();
        std::string& get_lastname();
        std::string& get_nickname();
        std::string& get_phone_number();
        std::string& get_darkest_secret();

        std::string& set_firstname();
        std::string& set_lastname();
        std::string& set_nickname();
        std::string& set_phone_number();
        std::string& set_darkest_secret();
};
