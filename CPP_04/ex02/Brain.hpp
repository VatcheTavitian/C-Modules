#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

# include <iostream>

class Brain
{
protected:
    std::string _ideas[100];

public:
    Brain();
    Brain(const Brain& toCopy);
    Brain& operator=(const Brain& src);
    virtual ~Brain();

};

#endif