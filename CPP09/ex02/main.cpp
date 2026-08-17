#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <positive integer sequence>" << std::endl;
        return 1;
    }

    try {
        PmergeMe p(argc, argv);
        p.sortAndPrint();
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
