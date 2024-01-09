#include "PMergeMe.hpp"
#include "PMergeMeList.hpp"

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cout << "Missing arguments" << std::endl;
        return (-1);
    }

    try {
        PMergeMe* pmergeme = new PMergeMe(argv, argc);
        pmergeme->sortVector(pmergeme->_vector.size());
        delete(pmergeme);
    } catch (PMergeMe::InvalidInput& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        PMergeMeList* pmergemeList = new PMergeMeList(argv, argc);
        pmergemeList->sortList(pmergemeList->_list.size());
        delete(pmergemeList);
    } catch (PMergeMeList::InvalidInput& e) {
        std::cout << e.what() << std::endl;
    }

}