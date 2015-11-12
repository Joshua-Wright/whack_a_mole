//
// Created by j0sh on 11/10/15.
//

#ifndef WHACK_A_MOLE_MATRIX_H
#define WHACK_A_MOLE_MATRIX_H

#include <stdexcept>
#include <cstring>

template<typename T>
class square_matrix {
    unsigned _size;
    T *data;
public:
    square_matrix(unsigned size) : _size(size) {
        data = new T[size * size];
        std::memset(data, 0, size * size * sizeof(T));
    };

    unsigned size() const {
        return _size;
    }

    unsigned n_elements() const {
        return _size * _size;
    }

    T *begin() { // first element
        return data;
    }

    T *end() { // past the end pointer
        return data + ((_size - 1) * _size + _size);
    }

    const T *begin() const { // first element
        return data;
    }

    const T *end() const { // past the end pointer
        return data + ((_size - 1) * _size + _size);
    }

    T &operator()(unsigned x, unsigned y) {
        if (x >= _size || y >= _size) {
            throw std::runtime_error("out of range");
        }
        return data[x * _size + y];
    }

    T &operator()(unsigned z) {
        if (z >= _size * _size) {
            throw std::runtime_error("out of range");
        }
        return data[z];
    }

};


#endif //WHACK_A_MOLE_MATRIX_H
