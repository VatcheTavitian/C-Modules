#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

# include <iostream>

template <typename T>
class Array {
    private:
        T*          _array;
        unsigned int _arrSize;

    public:
        Array(void) : _array(NULL), _arrSize(0) {
                std::cout << "Array Default constructor called" << std::endl;
                }
        Array(unsigned int n) :  _array(new T[n]), _arrSize(n) {
                std::cout << "Array Constructor called" << std::endl;
                }
        Array(const Array& toCopy) : _array(NULL){
            std::cout << "Array Copy Constructor called" << std::endl;
            *this = toCopy;
        }
        	
		Array& operator=(const Array& src) {
            std::cout << "Array Equal Asignment Operator called" << std::endl;
            if (this == &src)
                return (*this);
            if (this->_array)
                delete[] this->_array;
            this->_arrSize = src._arrSize;
            this->_array = new T[_arrSize];
            for (unsigned int i = 0; i < src._arrSize; i++)
                this->_array[i] = src._array[i];
            return (*this);
        }
        ~Array() { std::cout << "Array Destructor called" << std::endl;}

        unsigned int size() const { return this->_arrSize; }
        T&    operator[](unsigned int index) { 
            if (index < 0 || index >= this->size())
                throw Array::OutOfRange();
            else
                return this->_array[index]; }

        class OutOfRange: public std::exception {
            public:
				const char* what() const throw() {
                    return "Index is out of range";
                }
        };
    };


 

#endif