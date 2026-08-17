#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <climits>
#include <algorithm>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe&) {}
PmergeMe& PmergeMe::operator=(const PmergeMe&) { return *this; }
PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::parseArgs(int argc, char** argv) {
    std::vector<int> result;

    for (int i = 1; i < argc; i++) {
        std::string arg(argv[i]);
        if (arg.empty())
            throw std::runtime_error("Error");
        for (size_t j = 0; j < arg.size(); j++) {
            if (!std::isdigit(static_cast<unsigned char>(arg[j])))
                throw std::runtime_error("Error");
        }

        errno = 0;
        char* end;
        long value = std::strtol(arg.c_str(), &end, 10);
        if (errno == ERANGE || value < 0 || value > INT_MAX || *end != '\0')
            throw std::runtime_error("Error");

        result.push_back(static_cast<int>(value));
    }

    if (result.empty())
        throw std::runtime_error("Error");

    return result;
}

/* ---------------- vector-based Ford-Johnson (merge-insert sort) ---------------- */

static void insertSortedVector(std::vector<int>& chain, const std::vector<int>& original, int idx) {
    int lo = 0, hi = static_cast<int>(chain.size());
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (original[chain[mid]] < original[idx])
            lo = mid + 1;
        else
            hi = mid;
    }
    chain.insert(chain.begin() + lo, idx);
}

static std::vector<int> fjSortVector(const std::vector<int>& indices,
                                      const std::vector<int>& original,
                                      std::vector<int>& partner) {
    if (indices.size() <= 1)
        return indices;

    std::vector<int> winners;
    bool hasStraggler = false;
    int straggler = 0;

    for (size_t i = 0; i + 1 < indices.size(); i += 2) {
        int a = indices[i];
        int b = indices[i + 1];
        if (original[a] < original[b])
            std::swap(a, b);
        partner[a] = b;
        winners.push_back(a);
    }
    if (indices.size() % 2 == 1) {
        hasStraggler = true;
        straggler = indices[indices.size() - 1];
    }

    std::vector<int> sortedWinners = fjSortVector(winners, original, partner);

    std::vector<int> chain = sortedWinners;
    if (!chain.empty())
        chain.insert(chain.begin(), partner[chain[0]]);

    for (size_t i = 1; i < sortedWinners.size(); i++)
        insertSortedVector(chain, original, partner[sortedWinners[i]]);

    if (hasStraggler)
        insertSortedVector(chain, original, straggler);

    return chain;
}

void PmergeMe::sortVector(std::vector<int>& v) {
    if (v.size() <= 1)
        return;

    std::vector<int> indices;
    for (size_t i = 0; i < v.size(); i++)
        indices.push_back(static_cast<int>(i));

    std::vector<int> partner(v.size(), -1);
    std::vector<int> sortedIndices = fjSortVector(indices, v, partner);

    std::vector<int> sorted;
    for (size_t i = 0; i < sortedIndices.size(); i++)
        sorted.push_back(v[sortedIndices[i]]);
    v = sorted;
}

/* ---------------- deque-based Ford-Johnson (merge-insert sort) ---------------- */

static void insertSortedDeque(std::deque<int>& chain, const std::deque<int>& original, int idx) {
    int lo = 0, hi = static_cast<int>(chain.size());
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (original[chain[mid]] < original[idx])
            lo = mid + 1;
        else
            hi = mid;
    }
    chain.insert(chain.begin() + lo, idx);
}

static std::deque<int> fjSortDeque(const std::deque<int>& indices,
                                    const std::deque<int>& original,
                                    std::deque<int>& partner) {
    if (indices.size() <= 1)
        return indices;

    std::deque<int> winners;
    bool hasStraggler = false;
    int straggler = 0;

    for (size_t i = 0; i + 1 < indices.size(); i += 2) {
        int a = indices[i];
        int b = indices[i + 1];
        if (original[a] < original[b])
            std::swap(a, b);
        partner[a] = b;
        winners.push_back(a);
    }
    if (indices.size() % 2 == 1) {
        hasStraggler = true;
        straggler = indices[indices.size() - 1];
    }

    std::deque<int> sortedWinners = fjSortDeque(winners, original, partner);

    std::deque<int> chain = sortedWinners;
    if (!chain.empty())
        chain.insert(chain.begin(), partner[chain[0]]);

    for (size_t i = 1; i < sortedWinners.size(); i++)
        insertSortedDeque(chain, original, partner[sortedWinners[i]]);

    if (hasStraggler)
        insertSortedDeque(chain, original, straggler);

    return chain;
}

void PmergeMe::sortDeque(std::deque<int>& d) {
    if (d.size() <= 1)
        return;

    std::deque<int> indices;
    for (size_t i = 0; i < d.size(); i++)
        indices.push_back(static_cast<int>(i));

    std::deque<int> partner(d.size(), -1);
    std::deque<int> sortedIndices = fjSortDeque(indices, d, partner);

    std::deque<int> sorted;
    for (size_t i = 0; i < sortedIndices.size(); i++)
        sorted.push_back(d[sortedIndices[i]]);
    d = sorted;
}
