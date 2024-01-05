#include "PMergeMe.hpp"

PMergeMe::PMergeMe() {
    std::cout << "Default constructor called" << std::endl;
}

PMergeMe::PMergeMe(char** argv, int count) {
    // std::cout << "Constructor called" << std::endl;
    if (!this->_isValid(argv, count))
        throw (PMergeMe::InvalidInput());
    this->_addToVector(argv, count);
}

PMergeMe::PMergeMe(const PMergeMe& toCopy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = toCopy;
}

PMergeMe& PMergeMe::operator=(const PMergeMe& src) {
    if (this == &src)
        return (*this);
    // DEEP COPY content
    return (*this);
}

PMergeMe::~PMergeMe() {
    std::cout << "Destructor called" << std::endl;
}

bool PMergeMe::_isValid(char** argv, int count) {
    int i = 0;
    int x = 1;

    while (x < count) {
        while (argv[x][i]) {
            if (argv[x][i] != ' ' && !isdigit(argv[x][i])) {
                return (false);
            }
            i++;
        }
        i = 0;
        x++;
    }
    return (true);
}

void PMergeMe::_addToVector(char** argv, int count) {
    for (int i = 1; i < count; i++)
        this->_vector.push_back(std::atoi(argv[i]));
}

void PMergeMe::swapValues(int& value1, int& value2) {
    int temp = 0;
    if (value2 < value1) {
        temp = value1;
        value1 = value2;
        value2 = temp;
    }
// std::cout << value1 << value2 <<"\n";
}

void PMergeMe::sortVector(int size) {
    int     num = 0;
    bool    odd = false;

    if (size <= 1)
        return;
    //   std::cout << this->_vector.size() <<"\n";
    if (size % 2 != 0) {
        odd = true;
        num = this->_vector[this->_vector.size() - 1];
        this->_vector.pop_back();
        size--;
    }
    for (int i = 0; i < size; i += 2) {
         int temp = 0;
        if (this->_vector[i + 1] < this->_vector[i] ) {
            temp = this->_vector[i] ;
            this->_vector[i]  = this->_vector[i + 1] ;
            this->_vector[i + 1] = temp;
         }
    }

    // std::vector<int> large;
    // for (int i = 0; i < size; i += 2) {
    //     large.push_back(this->_vector[i + 1]);
    // }

    //  for (unsigned long i = 0; i < large.size(); i++)
    //         std::cout << large[i] << std::endl;

    // std::cout << this->_vector.size() <<"\n";
        //    for (unsigned long i = 0; i < this->_vector.size(); i++)
        //     std::cout << this->_vector[i] << std::endl;
  
 }

const char* PMergeMe::InvalidInput::what() const throw() {
		return "Error: invalid syntax";
	}