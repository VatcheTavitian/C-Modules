#include "PMergeMe.hpp"

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cout << "Missing arguments" << std::endl;
        return (-1);
    }

    try {
        PMergeMe* pmergeme = new PMergeMe(argv, argc);
        pmergeme->sortVector(pmergeme->_vector.size());
        // for (unsigned long i = 0; i < pmergeme->_vector.size(); i++)
        //     std::cout << pmergeme->_vector[i] << std::endl;
        delete(pmergeme);
    } catch (PMergeMe::InvalidInput& e) {
        std::cout << e.what() << std::endl;
    }
}