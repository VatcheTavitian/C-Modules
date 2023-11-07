#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "Animal.hpp"

class Dog : public Animal
{

public:
    Dog();
    Dog(const Dog& toCopy);
    Dog& operator=(const Dog& src);
    ~Dog();

    void    makeSound() const;
};

#endif