#ifndef __SPAN_HPP__
# define __SPAN_HPP__

# include <iostream>
# include <vector>
# include <cstdlib>

class Span
{
    private:
        Span();
        unsigned int _N;

    public:
        std::vector<int> _v;
        Span(unsigned int N);
        Span(const Span& tocopy);
        Span& operator=(const Span& src);
        ~Span();

    void    addNumber(int n);
    int     shortestSpan();
    int     longestSpan();

    void    addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
    void    printContents();
    static int     generator();

    class SpanExceptionSize: public std::exception {
        virtual const char* what() const throw();
    };

    class SpanExceptionError: public std::exception {
        virtual const char* what() const throw();
    };
};

#endif