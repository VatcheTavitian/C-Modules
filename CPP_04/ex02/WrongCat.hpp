#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__


# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

public:
    WrongCat();
    WrongCat(const WrongCat& toCopy);
    void operator=(const WrongCat& src);
    ~WrongCat();

    // void    makeSound() const;
};

#endif