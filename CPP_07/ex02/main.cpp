#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    // Main provided in subject
    {
        std::cout << "Main provided in subject...\n";
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        
        delete [] mirror;
    }

    // Main provided in checklist
    {
        std::cout << "\nMain provided in checklist...\n";
        Array<int>* emptyArray = new Array<int>();
        std::cout << "emptyArray Created at: " << emptyArray <<std::endl;

        try {
            std::cout << "emptyArray[0] = " << (*emptyArray)[0] << std::endl;
        } catch (std::exception& e) {
            std::cout << "Failed: " << e.what() <<std::endl;
        }
        delete emptyArray;


        std::cout << "\n\n";

        
        Array<int>* notEmptyArray = new Array<int>(5);
        std::cout << "Not Empty Array Created at: " << notEmptyArray <<std::endl;

        for (unsigned int i = 0; i < 5; i++)
            (*notEmptyArray)[i] = i * i;
       
        std::cout << "Array at index 3: " << (*notEmptyArray)[3] <<std::endl;
        (*notEmptyArray)[3] = 999;
        std::cout << "Array at index 3 is now: " << (*notEmptyArray)[3] <<std::endl;
        delete notEmptyArray;
    }
    
}