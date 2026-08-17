#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span& other) : _n(other._n), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _n = other._n;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
    if (_numbers.size() >= _n)
        throw Span::FullException();
    _numbers.push_back(value);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw Span::NoSpanException();

    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());

    int shortest = INT_MAX;
    for (size_t i = 1; i < sorted.size(); i++)
        shortest = std::min(shortest, sorted[i] - sorted[i - 1]);
    return shortest;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw Span::NoSpanException();

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
    return maxVal - minVal;
}

const char* Span::FullException::what() const throw() { return "Span is full."; }
const char* Span::NoSpanException::what() const throw() { return "Not enough elements to find a span."; }
