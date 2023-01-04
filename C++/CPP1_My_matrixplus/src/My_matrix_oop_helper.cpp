#include "My_matrix_oop.h"

// void MyMatrix::output_matrix() {
//     for (int i = 0; i < _rows; i++) {
//         for (int j = 0; j < _cols; j++) {
//             cout << _matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

int& MyMatrix::get_rows() { return _rows; }

int& MyMatrix::get_cols() { return _cols; }

double MyMatrix::get_index_matrix(int i, int j) { return _matrix[i][j]; }

void MyMatrix::set_rows(int value) { _rows = value; }

void MyMatrix::set_cols(int value) { _cols = value; }

void MyMatrix::set_index_matrix(double number, int i, int j) {
    _matrix[i][j] = number;
}

void MyMatrix::remove_matrix() {
    for (int i = 0; i < _rows; i++) {
        delete[] _matrix[i];
    }
    delete[] _matrix;
    _rows = 0;
    _cols = 0;
}
