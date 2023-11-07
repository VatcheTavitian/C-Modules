#ifndef CPP_04_ANIMAL_HPP
#define CPP_04_ANIMAL_HPP

# include <iostream>

class Animal {
protected:
    std::string _type;

public:
    Animal();
    Animal(const Animal& toCopy);
    void operator=(const Animal& src);
    virtual ~Animal();

    virtual void        makeSound() const;
    const std::string    getType() const;
};



#endif //CPP_04_ANIMAL_HPP
