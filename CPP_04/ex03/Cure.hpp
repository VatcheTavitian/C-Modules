#ifndef __CURE_HPP__
# define __CURE_HPP__


# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
private:
    std::string _type;

public:
    Cure();
    Cure(const Cure& toCopy);
    Cure& operator=(const Cure& src);
    ~Cure();

    AMateria* clone() const;
    std::string const& getType() const;
    void    setType(const std::string newType);
    void    use(ICharacter& target);
   

};

#endif