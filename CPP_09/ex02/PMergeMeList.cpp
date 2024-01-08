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
        this->_list.push_back(Node(std::atoi(argv[i])));
}

void PMergeMeList::swapValues(int& value1, int& value2) {
    int temp = 0;
    if (value2 < value1) {
        temp = value1;
        value1 = value2;
        value2 = temp;
    }
}

void PMergeMeList::merge(std::list<Node>& S, int left, int mid, int right) {
    (void) S;
    (void) left;
    (void) mid;
    (void) right;
    
    // int n1 = mid - left + 1;
    // int n2 = right - mid;

    // std::list<int> L(n1), R(n2);

    // for (int i = 0; i < n1; i++)
    //     L[i] = S[left + i];
    // for (int j = 0; j < n2; j++)
    //     R[j] = S[mid + 1 + j];

    // int i = 0, j = 0, k = left;

    // while (i < n1 && j < n2) {
    //     if (L[i] <= R[j]) {
    //         S[k] = L[i];
    //         i++;
    //     } else {
    //         S[k] = R[j];
    //         j++;
    //     }
    //     k++;
    // }

    // while (i < n1) {
    //     S[k] = L[i];
    //     i++;
    //     k++;
    // }

    // while (j < n2) {
    //     S[k] = R[j];
    //     j++;
    //     k++;
    // }
    
}


void PMergeMeList::mergeSort(std::list<Node>& S, int left, int right) {
  
    if (left < right) {
            
        int mid = left + (right - left) / 2;

        mergeSort(S, left, mid);
        mergeSort(S, mid + 1, right);

        merge(S, left, mid, right);
    }
}

void PMergeMeList::sortList(int size) {
 
    // Node     lastnum = this->_list.back();
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
 
    for (std::list<Node>::iterator it = this->_list.begin(); it != this->_list.end();) {
         std::cout << "Looking at " << it->value<< std::endl;
        std::list<Node>::iterator nextIt = it;
        nextIt++;
        if (it->value > nextIt->value )
            this->_list.splice(it, _list, nextIt);
        else
            it++;
        it++;

    }   

    std::list<Node> S;
     for (std::list<Node>::iterator it = this->_list.begin(); it != this->_list.end();) {
        it++;
        if (it == this->_list.end())
            break ;
        S.push_back(*it);
        it++;
    }
    
    std::cout << "Printing S\n";
    for (std::list<Node>::iterator it = S.begin(); it != S.end(); it++) {
         std::cout << it->value <<"\n";
    }
      

    // mergeSort(S, 0, S.size() - 1);


    // for (unsigned long i = 0; i < this->_vector.size(); i+=2) {
    //     for (unsigned long j = 0; j < S.size(); j++) {
    //         if (this->_vector[i] < S[j]) {
    //             S.insert(S.begin() + j, this->_vector[i]);
    //             break ;
    //         }
    //     }
    // }

    // this->_vector = S;

    // if (odd) {
    //     unsigned long i = 0;
    //     int current = INT_MIN;
    //     while (i <  this->_vector.size()) {
    //         if (num >= current && num <= this->_vector[i])
    //             break;
    //         current = this->_vector[i];
    //         i++;
    //     } 
    //     this->_vector.insert(this->_vector.begin() + i, num);
    // }
    // double finishTime = clock();
  
    // double totalTime = (finishTime - startTime) / CLOCKS_PER_SEC * 1000000;
    // // for (unsigned long i = 0; i < this->_vector.size(); i++)
    // //         std::cout << this->_vector[i] << std::endl;
    //  printValues("After: ");
    //  std::cout << "Time to process range of " << this->_vector.size() << " elements with std::vector " << totalTime << " us" << std::endl;
 }

void PMergeMeList::printValues(std::string pos) {
    std::cout << pos << ":   ";
    for (std::list<Node>::iterator it = this->_list.begin(); it != this->_list.end(); it++)
            std::cout << it->value  << " ";
    std::cout << "\n";
}

const char* PMergeMeList::InvalidInput::what() const throw() {
		return "Error: invalid syntax";
	}

    