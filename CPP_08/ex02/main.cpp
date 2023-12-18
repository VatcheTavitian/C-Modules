#include "MutantStack.hpp"

int main() {

    // Tests
    // {
    // MutantStack<int> mutantStack;
    // mutantStack.push(42);
    // mutantStack.push(12);
    // mutantStack.push(33);

    // MutantStack<int> mutantStack2;
    // mutantStack2.push(1);
    // mutantStack2.push(2);
 
    // MutantStack<int>* mutantStack3 = new MutantStack<int>(mutantStack2);
    // std::cout << mutantStack3->size()<< "= Size of Mutant Stack3 after copying stack2" << std::endl;

    // std::cout << mutantStack.empty()<< " empty " << std::endl;
    // std::cout << mutantStack.top()<< " = top" << std::endl;
    // mutantStack.push(20);

    // std::cout << mutantStack.size()<< " Size of stack1 before swap" << std::endl;
    // std::cout << mutantStack.size()<< " Size of stack2 before swap" << std::endl;
    // mutantStack.swap(mutantStack2);
    // std::cout << mutantStack.size()<< " Size of stack1 after swap " << std::endl;
    // std::cout << mutantStack.size()<< " Size of stack2 after swap" << std::endl;

    // mutantStack.pop();
    // }

    // Checklist test
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        // std::cout << mstack.top() << std::endl;
        mstack.pop();
        // std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        //copy stack
        std::stack<int> s(mstack);
        std::cout << s.size() << " = s.size" << std::endl;
        s.pop();
        std::cout << s.top() <<  " = s.top" << std::endl;
     
        return 0;
    }

}
// 
// 
// 5
// 3
// 5
// 737
// 0