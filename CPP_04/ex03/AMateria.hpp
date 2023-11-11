#ifndef __AMATERIA_HPP__
# define __AMATERIA_HPP__

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        AMateria();
        std::string _type;
    
    public:
        virtual ~ AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria& toCopy);
        AMateria& operator=(const AMateria& src);
        virtual std::string const & getType() const = 0; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target) = 0;

};
#endif