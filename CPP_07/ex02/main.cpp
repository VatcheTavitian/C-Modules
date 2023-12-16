#include "Array.hpp"

int main() {

    // // int * a = new int();
    // // std::cout << *a <<std::endl;
    // // delete a;

    // // test ints
    // {
    // Array<int>* arrayOfInts = new Array<int>(5);
  
    // // fill values
    // for (unsigned int i = 0; i < 5; i++)
    //     (*arrayOfInts)[i] = i * i;
    // // print values
    // for (unsigned int i = 0; i < 5; i++)
    //     std::cout << "(*arrayOfInts)" << &(*arrayOfInts)[i] << "[" << i << "] = " << (*arrayOfInts)[i] << std::endl;
    // std::cout << arrayOfInts->size() <<std::endl;
    // // copy to new array

    // Array<int>* arrayCopy = new Array<int>(*arrayOfInts);
    // for (unsigned int i = 0; i < 5; i++)
    //     std::cout << "(*arrayCopy)"  << &(*arrayCopy)[i] <<"[" << i << "] = " << (*arrayCopy)[i] << std::endl;
    // std::cout << arrayCopy->size() <<std::endl;
    // // test out of range exception
    // try {
    //     std::cout << (*arrayCopy)[5] <<std::endl;
    // }
    // catch (Array<int>::OutOfRange& e) {
    //     std::cout << "ERROR: " << e.what() <<std::endl;
    // }

    // delete arrayOfInts;
    // delete arrayCopy;
    // }

    // // Test strings
    // {
    // Array<std::string>* arrayOfStrings= new Array<std::string>(5);
  
    // // fill values
    // for (unsigned int i = 0; i < 5; i++)
    //     (*arrayOfStrings)[i] = "word" + std::to_string(i);
    // // print values
    // for (unsigned int i = 0; i < 5; i++)
    //     std::cout << "(*arrayOfStrings)" << &(*arrayOfStrings)[i] << "[" << i << "] = " << (*arrayOfStrings)[i] << std::endl;
    // std::cout << arrayOfStrings->size() <<std::endl;
    // // copy to new array

    // Array<std::string>* stringArrayCopy = new Array<std::string>(*arrayOfStrings);
    // for (unsigned int i = 0; i < 5; i++)
    //     std::cout << "(*stringArrayCopy)"  << &(*stringArrayCopy)[i] <<"[" << i << "] = " << (*stringArrayCopy)[i] << std::endl;
    // std::cout << stringArrayCopy->size() <<std::endl;
    // // test out of range exception
    // try {
    //     std::cout << (*stringArrayCopy)[5] <<std::endl;
    // }
    // catch (Array<std::string>::OutOfRange& e) {
    //     std::cout << "ERROR: " << e.what() <<std::endl;
    // }

    // delete arrayOfStrings;
    // delete stringArrayCopy;
    // }

    // Checklist Test
    {
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