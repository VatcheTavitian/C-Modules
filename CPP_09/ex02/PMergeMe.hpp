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

    void merge(std::vector<int>& arr, int left, int mid, int right);
    void printValues(std::string pos);
public:
    std::vector<int> _vector; // make private after testing
    PMergeMe(char** argv, int count);
    PMergeMe(const PMergeMe& toCopy);
    ~PMergeMe();

    void mergeSort(std::vector<int>& S, int left, int right);
    void sortVector(int size);
    void swapValues(int& value1, int& value2);
    // void mergeSort(std::vector<int>& S, int size);

    class InvalidInput: public std::exception {
        public:
				virtual const char* what() const throw();
    };
};

#endif