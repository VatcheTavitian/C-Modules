#include "Span.hpp"

int main() {

    // Span* s = new Span(5);
    // try {
    //     s->addNumber(1);
    //     s->addNumber(2);
    //     s->addNumber(3);
    //     s->addNumber(4);
    //     s->addNumber(5);
    //     s->addNumber(6);
    // } catch (const std::exception& e) {
    //     std::cout << e.what() << std::endl;
    // }
    // delete s;

    // Checklist tests
    Span sp = Span(5);
    sp.addNumber(-1);
    sp.addNumber(2);
    sp.addNumber(3);
    sp.addNumber(4);
    sp.addNumber(50);
    std::cout << "Shortest Span =" << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span = " << sp.longestSpan() << std::endl;

    // Throw Errors
    // Span sp = Span(5);
    // Span sp2 = Span(0);
    // sp.addNumber(1);
    // sp.addNumber(1);
    // sp.addNumber(1);
    // sp.addNumber(1);
    // sp.addNumber(1);

    // try {
    //     std::cout << sp2.shortestSpan() << std::endl;
    // } catch (const std::exception& e) {
    //     std::cout << e.what() << std::endl;
    // }

    // try {
    //     std::cout << sp.longestSpan() << std::endl;
    // } catch (const std::exception& e) {
    //     std::cout << e.what() << std::endl;
    // }
    
    // Add Many Random (dispose has random content)
    try {
        Span spRandom = Span(10);
        std::vector<int>dispose(10);
        std::generate(dispose.begin(),dispose.end(),Span::generator);
        std::cout << "\nAdding random numbers to span using generate member function\n";
        spRandom.addNumber(dispose.begin(), dispose.end());
        spRandom.printContents();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
}