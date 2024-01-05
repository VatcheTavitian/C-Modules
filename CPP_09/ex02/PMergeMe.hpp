#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

# include <iostream>
# include <vector>

class PMergeMe
{
private:

    PMergeMe();
    PMergeMe& operator=(const PMergeMe& src);
    bool _isValid(char** argv, int count);
    void _addToVector(char** argv, int count);


public:
    std::vector<int> _vector; // make private after testing
    PMergeMe(char** argv, int count);
    PMergeMe(const PMergeMe& toCopy);
    ~PMergeMe();

    void sortVector(int size);
    void swapValues(int& value1, int& value2);

    class InvalidInput: public std::exception {
        public:
				virtual const char* what() const throw();
    };
};

#endif