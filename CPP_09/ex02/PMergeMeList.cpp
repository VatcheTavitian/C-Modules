#include "PMergeMeList.hpp"

PMergeMeList::PMergeMeList() {
    std::cout << "Default constructor called" << std::endl;
}

PMergeMeList::PMergeMeList(char** argv, int count) {
    // std::cout << "Constructor called" << std::endl;
    if (!this->_isValid(argv, count))
        throw (PMergeMeList::InvalidInput());
    this->_addToList(argv, count);
}

PMergeMeList::PMergeMeList(const PMergeMeList& toCopy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = toCopy;
}

PMergeMeList& PMergeMeList::operator=(const PMergeMeList& src) {
    if (this == &src)
        return (*this);
    // DEEP COPY content
    return (*this);
}

PMergeMeList::~PMergeMeList() {
    std::cout << "Destructor called" << std::endl;
}

bool PMergeMeList::_isValid(char** argv, int count) {
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

void PMergeMeList::_addToList(char** argv, int count) {
    for (int i = 1; i < count; i++)
        this->_list.push_back(std::atoi(argv[i]));
        // this->_list.push_back(Node(std::atoi(argv[i])));
}

void PMergeMeList::swapValues(int& value1, int& value2) {
    int temp = 0;
    if (value2 < value1) {
        temp = value1;
        value1 = value2;
        value2 = temp;
    }
}

void PMergeMeList::merge(std::list<int>& S,  std::list<int>& firstHalf,  std::list<int>& secondHalf) {
    S.clear();

    std::list<int>::iterator itFirst = firstHalf.begin();
    std::list<int>::iterator itSecond = secondHalf.begin();

    while (itFirst != firstHalf.end() && itSecond != secondHalf.end()) {
        if (*itFirst < *itSecond) {
            S.push_back(*itFirst);
            itFirst++;
        } else {
            S.push_back(*itSecond);
            itSecond++;
        }
    }    
    S.insert(S.end(), itFirst, firstHalf.end());
    S.insert(S.end(), itSecond, secondHalf.end());
}


void PMergeMeList::mergeSort(std::list<int>& S) {
    if (S.size() <=1)
        return ;
  
    std::list<int>::iterator mid = S.begin();

    for (unsigned long i = 0; i < S.size() / 2; i++)
        mid++;
    std::list<int> firstHalf(S.begin(), mid); 
    std::list<int> secondHalf(mid, S.end()); 

    mergeSort(firstHalf);
    mergeSort(secondHalf);

    merge(S, firstHalf, secondHalf);

}

void PMergeMeList::sortList(int size) {
 
    int    lastnum = this->_list.back();
    bool    odd = false;
    // double startTime = std::clock();
  
    if (size <= 1)
        return;
    printValues("Before:");
    if (size % 2 != 0) {
        odd = true;
        this->_list.pop_back();
        size--;
    }
    // std::cout << "LastNum here is " << lastnum.value << std::endl;
    // std::cout << "ODD here is " << odd << std::endl;
    //  std::cout << "Size now  is " << _list.size() << std::endl;
 
    for (std::list<int>::iterator it = this->_list.begin(); it != this->_list.end();) {
        std::list<int>::iterator nextIt = it;
        nextIt++;
        if (*it > *nextIt ) {
            this->_list.splice(it, _list, nextIt); 
        }
        else
            it++;
        it++;

    }   

    std::list<int> S;
     for (std::list<int>::iterator it = this->_list.begin(); it != this->_list.end();) {
        it++;
        if (it == this->_list.end())
            break ;
        S.push_back(*it);
     
        std::list<int>::iterator eraseMe = it;
        it++;
              
                this->_list.erase(eraseMe);
       
    }
    
    std::cout << "Printing S before\n";
    for (std::list<int>::iterator it = S.begin(); it != S.end(); it++) {
         std::cout << *it <<"\n";
    }
      

    mergeSort(S);

     std::cout << "Printing S after\n";
    for (std::list<int>::iterator it = S.begin(); it != S.end(); it++) {
         std::cout << *it <<"\n";
    }

        std::cout << "Printing list after\n";
    for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++) {
         std::cout << *it <<"\n";
    }
    
for (std::list<int>::iterator listIt = this->_list.begin(); listIt != this->_list.end(); listIt++) {
    std::list<int>::iterator it = S.begin();

    while (it != S.end()) {
        std::list<int>::iterator nextIt = it;
        nextIt++;
        if (*listIt <= *it) {
            S.insert(it, *listIt);
            break ;
        }
        else if (nextIt == S.end()) {
            S.push_back(*listIt);
            break;
        }
        it++;
    }
}
    if (odd) {
        std::list<int>::iterator it = S.begin();

        while (it != S.end()) {
            std::list<int>::iterator nextIt = it;
            nextIt++;
            if (lastnum <= *it) {
                S.insert(it, lastnum);
                break ;
            }
            else if (nextIt == S.end()) {
                S.push_back(lastnum);
                break;
            }
            it++;
         }
        
    }

    this->_list = S;

    // double finishTime = clock();
  
    // double totalTime = (finishTime - startTime) / CLOCKS_PER_SEC * 1000000;
    // // for (unsigned long i = 0; i < this->_vector.size(); i++)
    // //         std::cout << this->_vector[i] << std::endl;
    //  printValues("After: ");
    //  std::cout << "Time to process range of " << this->_vector.size() << " elements with std::vector " << totalTime << " us" << std::endl;
 }

void PMergeMeList::printValues(std::string pos) {
    std::cout << pos << ":   ";
    for (std::list<int>::iterator it = this->_list.begin(); it != this->_list.end(); it++)
            std::cout << *it  << " ";
    std::cout << "\n";
}

const char* PMergeMeList::InvalidInput::what() const throw() {
		return "Error: invalid syntax";
	}

    