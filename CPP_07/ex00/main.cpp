#include "whatever.hpp"

// int main()  {
    // {
    // int a = 5;
    // int b = 10;
    // char c = '!';
    // char d = '?';

    // std::cout << "a = " << a << " b = " << b << std::endl;
    // swap(a,b);
    // std::cout << "a = " << a << " b = " << b << std::endl;

    // std::cout << "c = " << c << " d = " << d << std::endl;
    // swap(c, d);
    // std::cout << "c = " << c << " d = " << d << std::endl;

    // int i = 21;
    // int j = 11;
    // std::cout << "Min = " << min(i, j) << std::endl;
    // std::cout << "Min = " << min(c, d) << std::endl;

    // std::cout << "Max = " << max(i, j) << std::endl;
    // std::cout << "Max = " << max(c, d) << std::endl;
// }
    //  {
    //     int a = 2;
    //     int b = 3;
    //     ::swap( a, b );
    //     std::cout << "a = " << a << ", b = " << b << std::endl;
    //     std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    //     std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    //     std::string c = "chaine1";
    //     std::string d = "chaine2";
    //     ::swap(c, d);
    //     std::cout << "c = " << c << ", d = " << d << std::endl;
    //     std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    //     std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    //  }


// }

class Awesome
{
    public:
    Awesome(void): _n(0) { }
    Awesome( int n): _n(n) {}
    Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); } bool operator>( Awesome const & rhs) const { return (this->_n > rhs._n); } bool operator<( Awesome const & rhs) const { return (this->_n < rhs._n); } bool operator>=( Awesome const & rhs) const { return (this->_n >= rhs._n); } bool operator<=( Awesome const & rhs) const { return (this->_n <= rhs._n); } int get_n() const { return _n; }
    private:
    int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main(void)
{
    Awesome a(2), b(4);
    swap(a, b);
    std::cout << a << " " << b << std::endl;
    std::cout << max(a, b) << std::endl;
    std::cout << min(a, b) << std::endl;
}