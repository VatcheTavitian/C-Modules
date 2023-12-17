#ifndef __SPAN_HPP__
# define __SPAN_HPP__

# include <iostream>
# include <vector>

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

    void    addMany(std::vector<int>::iterator start, std::vector<int>::iterator end);
    void    printContents();

    class SpanExceptionFull: public std::exception {
        virtual const char* what() const throw();
    };

    class SpanExceptionError: public std::exception {
        virtual const char* what() const throw();
    };
};

#endif