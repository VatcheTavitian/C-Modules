#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain* _brain;

public:
    Dog();
    Dog(const Dog& toCopy);
    Dog& operator=(const Dog& src);
    virtual ~Dog();

    void    makeSound() const;
};

#endif