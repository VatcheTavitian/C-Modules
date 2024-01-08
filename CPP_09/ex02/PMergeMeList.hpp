#ifndef __PMergeMeListLIST_HPP__
# define __PMergeMeListLIST_HPP__

# include <iostream>
# include <list>

class PMergeMeList
{
private:

    struct Node {
        int value;
        Node* leftPtr;
        Node* rightPtr;

        Node(int newValue): value(newValue), leftPtr(NULL), rightPtr(NULL) {};
    };

    PMergeMeList();
    PMergeMeList& operator=(const PMergeMeList& src);
    bool _isValid(char** argv, int count);
    void _addToList(char** argv, int count);

    void merge(std::list<Node>& arr, int left, int mid, int right);

public:
    void printValues(std::string pos);
    std::list<Node> _list; // make private after testing
    PMergeMeList(char** argv, int count);
    PMergeMeList(const PMergeMeList& toCopy);
    ~PMergeMeList();

    void mergeSort(std::list<Node>& S, int left, int right);
    void sortList(int size);
    void swapValues(int& value1, int& value2);
  

    class InvalidInput: public std::exception {
        public:
				virtual const char* what() const throw();
    };
};

#endif