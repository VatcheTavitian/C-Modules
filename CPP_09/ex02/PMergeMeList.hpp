#ifndef __PMergeMeListLIST_HPP__
# define __PMergeMeListLIST_HPP__

# include <iostream>
# include <list>

class PMergeMeList
{
private:
    double _startTime;
    PMergeMeList();
    PMergeMeList& operator=(const PMergeMeList& src);
    bool _isValid(char** argv, int count);
    void _addToList(char** argv, int count);
    void _merge(std::list<int>& S,  std::list<int>& firstHalf,  std::list<int>& secondHalf);

public:
    std::list<int> _list;
    void printValues(std::string pos);
    PMergeMeList(char** argv, int count);
    PMergeMeList(const PMergeMeList& toCopy);
    ~PMergeMeList();

    void mergeSort(std::list<int>& S);
    void sortList(int size);

    class InvalidInput: public std::exception {
        public:
				virtual const char* what() const throw();
    };
};

#endif