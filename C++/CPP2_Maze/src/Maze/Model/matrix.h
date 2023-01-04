#ifndef SRC_MODEL_MATRIX_H_
#define SRC_MODEL_MATRIX_H_

#include <cmath>
#include <iomanip>
#include <iostream>

namespace Maze {

class MazeMatrix {
   public:
    MazeMatrix();
    MazeMatrix(int rows, int cols);
    MazeMatrix(int rows, int cols, const double data_massive[]);
    MazeMatrix(const MazeMatrix &other);
    MazeMatrix(MazeMatrix &&other);
    ~MazeMatrix();
    // Task general methods
    bool eq_matrix(const MazeMatrix &other);
    void sum_matrix(const MazeMatrix &other);
    void sub_matrix(const MazeMatrix &other);
    void mul_number(const double num);
    void mul_matrix(const MazeMatrix &other);
    MazeMatrix transpose();
    double determinant();
    MazeMatrix calc_complements();
    MazeMatrix inverse_matrix();
    void clear();
    // Helping methods
    void output_matrix();
    // Task methods: operators reloading
    MazeMatrix operator+(const MazeMatrix &other);
    MazeMatrix operator-(const MazeMatrix &other);
    MazeMatrix operator*(const MazeMatrix &other);
    friend MazeMatrix operator*(const double num, const MazeMatrix &matrix);
    friend MazeMatrix operator*(const MazeMatrix &matrix, const double num);
    bool operator==(const MazeMatrix &other);
    MazeMatrix &operator=(const MazeMatrix &other);
    MazeMatrix &operator=(MazeMatrix &&other);
    MazeMatrix &operator+=(const MazeMatrix &other);
    MazeMatrix &operator-=(const MazeMatrix &other);
    MazeMatrix &operator*=(const MazeMatrix &other);
    MazeMatrix &operator*=(const double num);
    double &operator()(int i, int j);
    // Task methods: accessor and mutator
    int get_rows();
    int get_cols();
    void set_rows(int value_rows);
    void set_cols(int value_cols);
    double **get_matrix();
    void set_index_matrix(int number, int i, int j);
    int get_index_matrix(int i, int j);

   private:
    int rows_, cols_;
    double **matrix_;
    void memory_allocation();
    void memory_free();
    MazeMatrix create_minor_matrix(int size, int rows_index, int cols_index);
};

MazeMatrix operator*(const double num, const MazeMatrix &matrix);
MazeMatrix operator*(const MazeMatrix &matrix, const double num);

}  // namespace Maze

#endif  //  SRC_MODEL_MATRIX_H_
