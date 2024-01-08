#include "PMergeMe.hpp"
#include "PMergeMeList.hpp"

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cout << "Missing arguments" << std::endl;
        return (-1);
    }

    // try {
    //     PMergeMe* pmergeme = new PMergeMe(argv, argc);
    //     // pmergeme->mergeInsert(pmergeme->_vector, 0, pmergeme->_vector.size() - 1);
    //     pmergeme->sortVector(pmergeme->_vector.size());
    //     // for (unsigned long i = 0; i < pmergeme->_vector.size(); i++)
    //     //     std::cout << pmergeme->_vector[i] << std::endl;
    //     delete(pmergeme);
    // } catch (PMergeMe::InvalidInput& e) {
    //     std::cout << e.what() << std::endl;
    // }

    PMergeMeList* newList = new PMergeMeList(argv,argc);
    // std::cout << "List size = " << newList->_list.size() << std::endl;
  
    newList->sortList(newList->_list.size());
      newList->printValues("TEST");
}