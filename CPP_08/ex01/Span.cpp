#include "Span.hpp"

Span::Span() {
}

Span::Span(unsigned int N) : _N(N) {
    std::cout << "Span constructor called with " << _N << std::endl;
}

Span::Span(const Span& toCopy) {
    std::cout << "Span copy constructor called" << std::endl;
    *this = toCopy;
}

Span& Span::operator=(const Span& src) {
    std::cout << "Span equal assignment operator called" << std::endl;
    if (this == &src)
        return (*this);
    this->_N = src._N;
    return (*this);
}

Span::~Span() {
    std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(int n) {
    if (this->_v.size() != this->_N)
        _v.push_back(n);
    else
        throw Span::SpanExceptionSize();
}

int Span::shortestSpan() {
    if (this->_v.size() < 2)
        throw Span::SpanExceptionError();
    int span = INT_MAX;
    int temp = 0;
    std::sort(_v.begin(), _v.end());
    std::vector<int>::iterator it;
    for (it = _v.begin(); it != _v.end(); it++) {
        if (it == _v.begin())
            temp = *it;
        else {
            if ((*it - temp) < span)
                span = (*it - temp);
            temp = *it;
        }
    }
    return span;
}

int Span::longestSpan() {
    int largest = INT_MIN;
    if (this->_v.size() < 2)
        throw Span::SpanExceptionError();
    std::sort(_v.begin(), _v.end());
    largest = _v[0] - _v[_v.size() - 1];
    return (abs(largest));
}

int     Span::generator() {
    return rand();
}

void    Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end) {
    if (_v.size() + std::distance(start, end) <= _N)
        _v.insert(_v.end(), start,end);
    else
        throw Span::SpanExceptionSize();
}

void Span::printContents() {
    std::vector<int>::iterator it;
    for (it = _v.begin(); it != _v.end(); it++)
        std::cout << *it << " Value " << std::endl;
}

const char* Span::SpanExceptionSize::what() const throw () {
    return "Error: Span container too small!";
}

const char* Span::SpanExceptionError::what() const throw () {
    return "Error: Unable to calculate";
}
