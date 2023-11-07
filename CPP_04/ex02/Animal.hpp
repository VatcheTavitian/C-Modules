#ifndef CPP_04_ANIMAL_HPP
#define CPP_04_ANIMAL_HPP

# include <iostream>

class Animal {
private:
    Animal();

protected:
    std::string _type;

public:
    Animal(const std::string& type);
    Animal(const Animal& toCopy) ;
    Animal& operator=(const Animal& src) ;
    virtual ~Animal();

    virtual void        makeSound() const = 0;
    void    setType(const std::string& type);
    const std::string    getType() const;
};



#endif //CPP_04_ANIMAL_HPP
