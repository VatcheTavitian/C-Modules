#ifndef __ICE_HPP__
# define __ICE_HPP__

# include <iostream>
# include "AMateria.hpp"


class Ice : public AMateria
{
private:
    std::string _type;

public:
    Ice();
    Ice(const Ice& toCopy);
    Ice& operator=(const Ice& src);
    ~Ice();

    AMateria* clone() const;
    std::string const& getType() const;
    void    setType(const std::string newType);
    void    use(ICharacter& target);

};

#endif