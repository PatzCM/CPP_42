#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "=== addRange with 10000 numbers ===" << std::endl;
    std::srand(std::time(NULL));
    std::vector<int> big;
    for (int i = 0; i < 10000; i++)
        big.push_back(std::rand());

    Span huge(10000);
    huge.addRange(big.begin(), big.end());
    std::cout << "shortest: " << huge.shortestSpan() << std::endl;
    std::cout << "longest: " << huge.longestSpan() << std::endl;

    std::cout << "=== error cases ===" << std::endl;
    try {
        Span empty(2);
        empty.addNumber(1);
        empty.shortestSpan();
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Span full(1);
        full.addNumber(1);
        full.addNumber(2);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
