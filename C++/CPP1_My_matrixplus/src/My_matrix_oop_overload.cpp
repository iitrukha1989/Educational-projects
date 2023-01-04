#include "My_matrix_oop.h"

void MyMatrix::operator+(const MyMatrix& other) {
    if (_rows != other._rows || _cols != other._cols) {
        throw std::out_of_range(
            "Incorrect input, different dimension of matrices");
    } else {
        this->sum_matrix(other);
    }
}

void MyMatrix::operator-(const MyMatrix& other) {
    if (_rows != other._rows || _cols != other._cols) {
        throw std::out_of_range(
            "Incorrect input, different dimension of matrices");
    } else {
        this->sub_matrix(other);
    }
}

void MyMatrix::operator*(const MyMatrix& other) {
    if (_cols != other._rows) {
        throw std::out_of_range(
            "Incorrect input, different dimension of matrices");
    } else {
        this->mul_matrix(other);
    }
}

void MyMatrix::operator*(const double number) { this->mul_number(number); }

bool MyMatrix::operator==(const MyMatrix& other) {
    bool result;
    result = this->eq_matrix(other);
    return result;
}

MyMatrix MyMatrix::operator=(const MyMatrix& other) {
    this->remove_matrix();
    this->set_rows(other._rows);
    this->set_cols(other._cols);
    _matrix = new double*[_rows];
    for (int i = 0; i < _rows; i++) {
        _matrix[i] = new double[_cols];
    }
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            _matrix[i][j] = other._matrix[i][j];
        }
    }
    return *this;
}

void MyMatrix::operator+=(const MyMatrix& other) { this->sum_matrix(other); }

void MyMatrix::operator-=(const MyMatrix& other) { this->sub_matrix(other); }

void MyMatrix::operator*=(const MyMatrix& other) { this->mul_matrix(other); }

void MyMatrix::operator*=(const double number) { this->mul_number(number); }

double MyMatrix::operator()(int i, int j) {
    double result = 0;
    int flag = 0;
    for (int l = 0; l < _rows; l++) {
        for (int k = 0; k < _cols; k++) {
            if (i == l && j == k) {
                result = _matrix[l][k];
                flag++;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
    }
    return result;
}
