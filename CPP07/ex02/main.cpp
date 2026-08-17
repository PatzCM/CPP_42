#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i * 10;

    Array<int> b(a);
    b[0] = 999;

    std::cout << "a: ";
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    std::cout << "b: ";
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    Array<std::string> s(3);
    s[0] = "foo";
    s[1] = "bar";
    s[2] = "baz";
    std::cout << "s: " << s[0] << " " << s[1] << " " << s[2] << std::endl;

    Array<int> empty;
    std::cout << "empty size: " << empty.size() << std::endl;

    try {
        std::cout << a[100] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
