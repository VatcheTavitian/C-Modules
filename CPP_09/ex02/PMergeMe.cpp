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

void PMergeMe::merge(std::vector<int>& S, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;



    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = S[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = S[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            S[k] = L[i];
            i++;
        } else {
            S[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        S[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        S[k] = R[j];
        j++;
        k++;
    }
    
}


void PMergeMe::mergeSort(std::vector<int>& S, int left, int right) {
  
    if (left < right) {
            
        int mid = left + (right - left) / 2;

        mergeSort(S, left, mid);
        mergeSort(S, mid + 1, right);

        merge(S, left, mid, right);
    }
}

void PMergeMe::sortVector(int size) {
    int     num = 0;
    bool    odd = false;
    double startTime = std::clock();
  
    if (size <= 1)
        return;
    printValues("Before:");
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
    std::vector<int> S;
    for (unsigned long i = 1; i < this->_vector.size(); i += 2) {
       S.push_back(this->_vector[i]);
    }
      

    mergeSort(S, 0, S.size() - 1);


    for (unsigned long i = 0; i < this->_vector.size(); i+=2) {
        for (unsigned long j = 0; j < S.size(); j++) {
            if (this->_vector[i] < S[j]) {
                S.insert(S.begin() + j, this->_vector[i]);
                break ;
            }
        }
    }

    this->_vector = S;

    if (odd) {
        unsigned long i = 0;
        int current = INT_MIN;
        while (i <  this->_vector.size()) {
            if (num >= current && num <= this->_vector[i])
                break;
            current = this->_vector[i];
            i++;
        } 
        this->_vector.insert(this->_vector.begin() + i, num);
    }
    double finishTime = clock();
  
    double totalTime = (finishTime - startTime) / CLOCKS_PER_SEC * 1000000;
    // for (unsigned long i = 0; i < this->_vector.size(); i++)
    //         std::cout << this->_vector[i] << std::endl;
     printValues("After: ");
     std::cout << "Time to process range of " << this->_vector.size() << " elements with std::vector " << totalTime << " us" << std::endl;
 }

void PMergeMe::printValues(std::string pos) {
    std::cout << pos << ":   ";
    for (unsigned long i = 0; i < this->_vector.size(); i++)
            std::cout << this->_vector[i] << " ";
    std::cout << "\n";
}

const char* PMergeMe::InvalidInput::what() const throw() {
		return "Error: invalid syntax";
	}

    