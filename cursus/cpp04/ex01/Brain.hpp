#ifndef BRAIN_HPP
#define  BRAIN_HPP

#include <iostream>

class Brain {
    std::string ideas[100];
    public:
        Brain( void );
        Brain( const Brain &oldObj );
        Brain &operator=( const Brain &oldObj );
        ~Brain( void );

        const std::string getIdea( int i ) const;
        void setIdea( std::string idea, int i );
        void ideaAddr( void );
};

#endif