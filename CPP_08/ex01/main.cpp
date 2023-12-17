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
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

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
    
    // Add Many Random
    Span spRandom = Span(10);
    spRandom.addMany(spRandom._v.begin(), spRandom._v.end());
    // spRandom.printContents();

 
}