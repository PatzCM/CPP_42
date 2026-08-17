#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printElem(T const& x) {
    std::cout << x << std::endl;
}

void doubleIt(int& x) {
    x *= 2;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "=== int array ===" << std::endl;
    ::iter(arr, 5, printElem<int>);

    std::cout << "=== double each ===" << std::endl;
    ::iter(arr, 5, doubleIt);
    ::iter(arr, 5, printElem<int>);

    std::string strs[] = {"hello", "world", "42"};
    std::cout << "=== string array ===" << std::endl;
    ::iter(strs, 3, printElem<std::string>);

    const int carr[] = {10, 20, 30};
    std::cout << "=== const int array ===" << std::endl;
    ::iter(carr, 3, printElem<int>);

    return 0;
}
