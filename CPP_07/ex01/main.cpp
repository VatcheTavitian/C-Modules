#include "iter.hpp"


int main() {
    int nums[5] = {1, 2, 3, 4, 5};
    double doubles[5] = {1.99, 2.65, 369.5, -4.5, 5.66};
    char chars[5] = {'a', 'b', 'c', 'd', 'e'};
    std::string words[5] = {"hello", "there", "testing", "templates", "c++"};
    iter(nums, 5,  printFunction);
    iter(doubles, 5, printFunction);
    iter(chars, 5, printFunction);
    iter(words, 5, printFunction);

    iter(nums, 5, square);
    iter(doubles, 5, square);
    iter(chars, 5, square);
}