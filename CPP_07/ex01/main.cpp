#include "iter.hpp"

// My Main

// int main() {
//     int nums[5] = {1, 2, 3, 4, 5};
//     double doubles[5] = {1.99, 2.65, 369.5, -4.5, 5.66};
//     char chars[5] = {'a', 'b', 'c', 'd', 'e'};
//     std::string words[5] = {"hello", "there", "testing", "templates", "c++"};
//     iter(nums, 5,  printFunction);
//     iter(doubles, 5, printFunction);
//     iter(chars, 5, printFunction);
//     iter(words, 5, printFunction);

//     iter(nums, 5, square);
//     iter(doubles, 5, square);
//     iter(chars, 5, square);
// }



// Checklist Main

class Awesome
{
    public:
        Awesome( void ): _n( 42 ) { return; }
        int get( void ) const { return this->_n; }
    private:
        int _n;
};
std::ostream & operator<<(std::ostream & o, Awesome const & rhs) { o<< rhs.get(); return o; }



int main() {
    int tab[] = { 0, 1, 2, 3, 4 }; 
    Awesome tab2[5];
    iter(tab, 5, print); 
    iter(tab2, 5, print);
    return 0;
}