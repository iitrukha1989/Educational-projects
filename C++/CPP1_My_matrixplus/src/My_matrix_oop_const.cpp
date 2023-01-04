#include "My_matrix_oop.h"

MyMatrix::MyMatrix() {
    _rows = 3;
    _cols = 3;
    _matrix = new double*[_rows];
    for (int i = 0; i < _rows; i++) {
        _matrix[i] = new double[_cols];
    }
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            _matrix[i][j] = 0;
        }
    }
}

MyMatrix::MyMatrix(int rows, int cols) : _rows(rows), _cols(cols) {
    _matrix = new double*[_rows];
    for (int i = 0; i < _rows; i++) {
        _matrix[i] = new double[_cols];
    }
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            _matrix[i][j] = 0;
        }
    }
}

MyMatrix::MyMatrix(const MyMatrix& other)
    : _rows(other._rows), _cols(other._cols) {
    _matrix = new double*[_rows];
    for (int i = 0; i < _rows; i++) {
        _matrix[i] = new double[_cols];
    }
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            _matrix[i][j] = other._matrix[i][j];
        }
    }
}

MyMatrix::MyMatrix(MyMatrix&& other) {
    _rows = other._rows;
    _cols = other._cols;
    _matrix = other._matrix;
    other._matrix = nullptr;
}

MyMatrix::~MyMatrix() {
    if (_matrix) {
        for (int i = 0; i < _rows; i++) {
            delete[] _matrix[i];
        }
        delete[] _matrix;
    }
}
