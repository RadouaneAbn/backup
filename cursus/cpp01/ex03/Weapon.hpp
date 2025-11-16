#pragma once

#include <iostream>

class Weapon {
    private:
        std::string _type;
    
    public:
        Weapon ( std::string type ) : _type(type) {};
        ~Weapon () {} ;
        void setType( std::string type );  
        const std::string& getType( void ) const;  
};