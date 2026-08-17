#pragma once

#include <stdexcept>

template <typename T>
class Array {
private:
    T*           _data;
    unsigned int _size;

public:
    Array() : _data(new T[0]()), _size(0) {}

    Array(unsigned int n) : _data(new T[n]()), _size(n) {}

    Array(const Array& other) : _data(new T[other._size]()), _size(other._size) {
        for (unsigned int i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }

    ~Array() { delete[] _data; }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            _data = new T[_size]();
            for (unsigned int i = 0; i < _size; i++)
                _data[i] = other._data[i];
        }
        return *this;
    }

    T& operator[](unsigned int i) {
        if (i >= _size)
            throw std::out_of_range("Array: index out of bounds");
        return _data[i];
    }

    T const& operator[](unsigned int i) const {
        if (i >= _size)
            throw std::out_of_range("Array: index out of bounds");
        return _data[i];
    }

    unsigned int size() const { return _size; }
};
