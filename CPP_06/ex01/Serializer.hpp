#ifndef __SERIALIZER_HPP__
# define __SERIALIZER_HPP__

# include <iostream>
# include <stdint.h>

typedef struct Data {
    int x;
 } Data;

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer& toCopy);
        Serializer& operator=(const Serializer& src);

    public:
       
        static uintptr_t serialize(Data* ptr);        

};

#endif