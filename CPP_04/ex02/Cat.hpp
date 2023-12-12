#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain* _brain;

public:
    Cat();
    Cat(const Cat& toCopy);
    Cat& operator=(const Cat& src);
    virtual ~Cat();

    void    makeSound() const;
};

#endif