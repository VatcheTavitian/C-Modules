#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

# include <iostream>

class WrongAnimal {
protected:
    std::string _type;

public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& toCopy);
    void operator=(const WrongAnimal& src);
    virtual ~WrongAnimal();

    void        makeSound() const;
    const std::string    getType() const;
};

#endif