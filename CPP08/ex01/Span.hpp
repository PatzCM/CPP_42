#pragma once

#include <vector>
#include <iterator>
#include <stdexcept>
#include <exception>

class Span {
private:
    unsigned int      _n;
    std::vector<int>  _numbers;

public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int value);

    template <typename InputIterator>
    void addRange(InputIterator begin, InputIterator end) {
        if (_numbers.size() + static_cast<unsigned long>(std::distance(begin, end)) > _n)
            throw std::length_error("Span: not enough space");
        _numbers.insert(_numbers.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;

    class FullException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NoSpanException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};
