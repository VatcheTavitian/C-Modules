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

// void PMergeMe::mergeSort(std::vector<int>& S, int size) {
//     int num = 0;
//     bool odd = false;
    
  


//     if (size <= 1)
//         return ;
//     if (S.size() % 2 != 0) {
//         odd = true;
//         num = S.back();
//         S.pop_back();
//         size--;
//     }
//     for (int i = 0; i < size; i += 2) 
//         swapValues(S[i], S[i + 1]);

//     unsigned long i = 0;
//     while (i < 2) {
//         if (S[i + 1] < S[i]) {
//             std::cout << "S[i + 2] < S[i] = " << S[i + 1] << S[i] << std::endl;
//             swapValues(S[i], S[i + 2]);
//         }
//         i++;
//     }


//     if (odd) {
//         unsigned long i = 0;
//         while (i < S.size() && S[i + 1] < num)
//             i++;
//         S.insert(S.begin() + i, num);
//     }
//     int mid = size / 2;
//     mergeSort(S, mid);
//     mergeSort(S, size - mid);
// }

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
    std::vector<int> S;
    for (unsigned long i = 1; i < this->_vector.size(); i += 2) {
       S.push_back(this->_vector[i]);
    }
      
    // mergeSort(S, S.size());

    mergeSort(S, 0, S.size() - 1);

    // std::cout << "Entered" << std::endl;
    // for (unsigned long i = 0; i < _vector.size(); i++)
    //                 std::cout << _vector[i] << std::endl;
    //         std::cout << "\n" << std::endl;

    // for (unsigned long i = 0; i < S.size(); i++)
    //         std::cout << S[i] << std::endl;

    for (unsigned long i = 0; i < this->_vector.size(); i+=2) {
        for (unsigned long j = 0; j < S.size(); j++) {
            if (this->_vector[i] < S[j]) {
                S.insert(S.begin() + j, this->_vector[i]);
                break ;
            }
        }
    }

  

    //     // std::cout << " this->_vector[i] = " <<  this->_vector[i] << std::endl;
    //     //  std::cout << "S[i] = " << S[i] << std::endl;
    //     for (unsigned long j = 1; j < S.size(); j+=2)
    //         if (this->_vector[i] < S[j]) {
    //             S.insert(S.begin() + i, this->_vector[i]);
    //             // std::cout << " STUCK this->_vector[i] = " <<  this->_vector[i] << " S[j] = " <<  S[j] << std::endl;
    //         }
    // }

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
    for (unsigned long i = 0; i < this->_vector.size(); i++)
            std::cout << this->_vector[i] << std::endl;
  
 }


// void PMergeMe::merge(std::vector<int>& arr, int left, int mid, int right) {
//     int num1 = mid - left + 1;
//     int num2 = right - mid;

//     std::vector<int> L(num1);
//     std::vector<int> R(num2);

//     for (int i = 0; i < num1; i++)
//         L[i] = arr[left + i];
//     for (int i = 0; i < num2; i++)
//         R[i] = arr[mid + i + 1];

    

//     for(int i = 0; i < static_cast<int>(R.size()); i++) {
//         std::cout << "Starting with  -> " << L.size() << std::endl;
//         int number = L[i];
//         int j = 0;
//         while (j < static_cast<int>(R.size()) && number > R[j]) {
//             j++;
//         }
//         R.insert(R.begin() + j, number);
//         std::cout << "INSERTED -> " << number << std::endl;
//     }
    
    // while (i < num1 && j < num2) {
    //     if (L[i] <= R[j]) {
    //         arr[k] = L[i];
    //         i++;
    //     } else {
    //         arr[k] = R[j];
    //         j++;
    //     }
    //     k++;
    // }

    // Copy the remaining elements of L[], if there are any
    // while (i < num1) {
    //     arr[k] = L[i];
    //     i++;
    //     k++;
    // }

    // // Copy the remaining elements of R[], if there are any
    // while (j < num2) {
    //     arr[k] = R[j];
    //     j++;
    //     k++;
    // }
    
// }

// void PMergeMe::mergeInsert(std::vector<int> vect, int left, int right) {
//     if (left < right) {
//         int midValue = left + (right - left) / 2;
    
//     mergeInsert(vect, left, midValue);
//     mergeInsert(vect, midValue + 1, right);

//     merge(vect, left, midValue, right);

//     }
// }

const char* PMergeMe::InvalidInput::what() const throw() {
		return "Error: invalid syntax";
	}

    