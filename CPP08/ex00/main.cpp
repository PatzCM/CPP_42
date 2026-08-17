#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);

    try {
        std::vector<int>::iterator it = easyfind(v, 5);
        std::cout << "Found: " << *it << std::endl;
        it = easyfind(v, 42);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::list<int> l;
    l.push_back(100);
    l.push_back(200);
    l.push_back(300);
    try {
        std::list<int>::iterator it = easyfind(l, 200);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
