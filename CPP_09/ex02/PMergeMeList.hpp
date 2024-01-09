#ifndef __PMergeMeListLIST_HPP__
# define __PMergeMeListLIST_HPP__

# include <iostream>
# include <list>

class PMergeMeList
{
private:

    PMergeMeList();
    PMergeMeList& operator=(const PMergeMeList& src);
    bool _isValid(char** argv, int count);
    void _addToList(char** argv, int count);

    void merge(std::list<int>& S,  std::list<int>& firstHalf,  std::list<int>& secondHalf);

public:
    void printValues(std::string pos);
    std::list<int> _list; // make private after testing
    PMergeMeList(char** argv, int count);
    PMergeMeList(const PMergeMeList& toCopy);
    ~PMergeMeList();

    void mergeSort(std::list<int>& S);
    void sortList(int size);
    void swapValues(int& value1, int& value2);
  

    class InvalidInput: public std::exception {
        public:
				virtual const char* what() const throw();
    };
};

#endif