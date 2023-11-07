#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"

class Cat : public Animal
{

public:
    Cat();
    Cat(const Cat& toCopy);
    Cat& operator=(const Cat& src);
    ~Cat();

    void    makeSound() const;
};

#endif