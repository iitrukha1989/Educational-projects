#include "My_matrix_oop.h"

bool MyMatrix::eq_matrix(const MyMatrix& other) {
    bool result = false;
    double tmp_precision = 1e7;
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            if ((int)_matrix[i][j] * tmp_precision ==
                (int)other._matrix[i][j] * tmp_precision) {
                result = true;
            } else {
                result = false;
                break;
            }
        }
    }
    return result;
}

void MyMatrix::sum_matrix(const MyMatrix& other) {
    if (_rows != other._rows || _cols != other._cols) {
        throw std::out_of_range(
            "Incorrect input, different dimension of matrices");
    } else {
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                _matrix[i][j] = _matrix[i][j] + other._matrix[i][j];
            }
        }
    }
}

void MyMatrix::sub_matrix(const MyMatrix& other) {
    if (_rows != other._rows || _cols != other._cols) {
        throw std::out_of_range(
            "Incorrect input, different dimension of matrices");
    } else {
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                _matrix[i][j] = _matrix[i][j] - other._matrix[i][j];
            }
        }
    }
}

void MyMatrix::mul_number(const double number) {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            _matrix[i][j] = _matrix[i][j] * number;
        }
    }
}

void MyMatrix::mul_matrix(const MyMatrix& other) {
    if (_cols != other._rows) {
        throw std::out_of_range(
            "Incorrect input, different dimension of matrices");
    } else {
        MyMatrix tmp_matrix(_rows, other._cols);
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < other._cols; j++) {
                for (int k = 0; k < _cols; k++) {
                    tmp_matrix._matrix[i][j] +=
                        (_matrix[i][k] * other._matrix[k][j]);
                }
            }
        }
        this->remove_matrix();
        this->set_rows(tmp_matrix._rows);
        this->set_cols(tmp_matrix._cols);
        _matrix = new double*[_rows];
        for (int i = 0; i < _rows; i++) {
            _matrix[i] = new double[_cols];
        }
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                _matrix[i][j] = tmp_matrix._matrix[i][j];
            }
        }
    }
}

MyMatrix MyMatrix::transpose() {
    MyMatrix tmp_matrix(_cols, _rows);
    for (int i = 0; i < _cols; i++) {
        for (int j = 0; j < _rows; j++) {
            tmp_matrix._matrix[i][j] = _matrix[j][i];
        }
    }
    tmp_matrix.set_rows(_cols);
    tmp_matrix.set_cols(_rows);
    return tmp_matrix;
}

MyMatrix MyMatrix::calc_complements() {
    if (_rows != _cols) {
        throw std::out_of_range("Incorrect input, the matrix is not square");
    } else {
        MyMatrix tmp_matrix_1(_rows, _cols);
        MyMatrix tmp_matrix_2(_rows - 1, _cols - 1);
        for (int i = 0; i < tmp_matrix_1._rows; i++) {
            for (int j = 0; j < tmp_matrix_1._cols; j++) {
                int index_minor_1 = 0;
                int index_minor_2 = 0;
                for (int k = 0; k < tmp_matrix_1._rows; k++) {
                    for (int l = 0; l < tmp_matrix_1._cols; l++) {
                        if (i != k && j != l) {
                            tmp_matrix_2._matrix[index_minor_1][index_minor_2] =
                                _matrix[k][l];
                            index_minor_2++;
                            if (index_minor_2 == tmp_matrix_1._cols - 1) {
                                index_minor_1++;
                                index_minor_2 = 0;
                            }
                        }
                    }
                }
                tmp_matrix_1._matrix[i][j] =
                    tmp_matrix_2.determinant() * pow(-1, i + j + 2);
            }
        }
        return tmp_matrix_1;
    }
}

double MyMatrix::determinant() {
    if (_rows != _cols) {
        throw std::out_of_range("Incorrect input, the matrix is not square");
    } else {
        double result = 0;
        if (_rows == 2) {
            result =
                _matrix[0][0] * _matrix[1][1] - _matrix[1][0] * _matrix[0][1];
        } else {
            for (int k = 0; k < _rows; k++) {
                int tmp_size = _rows - 1;
                MyMatrix tmp_matrix(tmp_size, tmp_size);
                for (int i = 1; i < _rows; i++) {
                    int tmp_index = 0;
                    for (int j = 0; j < _rows; j++) {
                        if (j != k) {
                            tmp_matrix._matrix[i - 1][tmp_index] =
                                _matrix[i][j];
                            tmp_index++;
                        }
                    }
                }
                result +=
                    pow(-1, k + 2) * _matrix[0][k] * tmp_matrix.determinant();
            }
        }
        return result;
    }
}

MyMatrix MyMatrix::inverse_matrix() {
    MyMatrix tmp_matrix_1(_rows, _cols);
    MyMatrix tmp_matrix_2(_rows, _cols);
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            tmp_matrix_1._matrix[i][j] = _matrix[i][j];
        }
    }
    double tmp_determinant = 1.0 / tmp_matrix_1.determinant();
    tmp_matrix_2 = tmp_matrix_1.calc_complements();
    tmp_matrix_1 = tmp_matrix_2.transpose();
    tmp_matrix_1.mul_number(tmp_determinant);
    return tmp_matrix_1;
}
