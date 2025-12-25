#ifndef AMATERIA_H
# define AMATERIA_H

# include <iostream>
# include <string>
class ICharacter; // forward declaration to avoid circular include

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria(std::string const & type);
        virtual ~AMateria( void );
        AMateria( const AMateria & oldObj );
        AMateria& operator=( const AMateria & oldObj );

        std::string const & getType() const; //Returns the materia type
        void setType( std::string type );
        virtual AMateria* clone(void) const = 0;
        virtual void use(ICharacter& target);
};


#endif