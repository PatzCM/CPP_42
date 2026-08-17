#pragma once

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    static std::vector<int> parseArgs(int argc, char** argv);

    static void sortVector(std::vector<int>& v);
    static void sortDeque(std::deque<int>& d);
};
