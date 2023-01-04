#ifndef SRC_My_MATRIX_OOP_H__
#define SRC_My_MATRIX_OOP_H__

//*  PROJECT: My_MATRIXPLUS
//*  Developer: aedie

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

class MyMatrix {
   private:
    int _rows, _cols;
    double** _matrix;

   public:
    // ===== Constuct and distruct methods =====
    // 1. Basic construnt
    MyMatrix();
    // 2. Construct with setting
    MyMatrix(int rows, int cols);
    // 3. Construct with copy other matrix
    MyMatrix(const MyMatrix& other);
    // 4. Construct with cut other matrix
    MyMatrix(MyMatrix&& other);
    // 5. Distruct
    ~MyMatrix();

    // ===== Operators/methods on the matrix =====
    // 6. Equal matrix
    bool eq_matrix(const MyMatrix& other);
    // 7. Sum matrix
    void sum_matrix(const MyMatrix& other);
    // 8. Sub matrix
    void sub_matrix(const MyMatrix& other);
    // 9. Mul matrix on number
    void mul_number(const double num);
    // 10. Mul matrix on other matrix
    void mul_matrix(const MyMatrix& other);
    // 11. Transpore matrix
    MyMatrix transpose();
    // 12. Calc complements matrix
    MyMatrix calc_complements();
    // 13. Determinant matrix
    double determinant();
    // 14. Invers matrix
    MyMatrix inverse_matrix();

    // ==== Overload operators/methods on the matrix =====
    // 15. Overload sum matrix
    void operator+(const MyMatrix& other);
    // 16. Overload sub matrix
    void operator-(const MyMatrix& other);
    // 17. Overload mul matrix
    void operator*(const MyMatrix& other);
    // 18. Overload mul number
    void operator*(const double number);
    // 19. Overload equal matrix
    bool operator==(const MyMatrix& other);
    // 20. Overload copy matrix
    MyMatrix operator=(const MyMatrix& other);
    // 21. Overload sum-equal matrix
    void operator+=(const MyMatrix& other);
    // 22. Overload sub-equal matrix
    void operator-=(const MyMatrix& other);
    // 23. Overload mul-equal matrix
    void operator*=(const MyMatrix& other);
    // 24. Overload mul-equal number
    void operator*=(const double number);
    // 25. Overload index matrix
    double operator()(int row, int col);

    // ===== Helper operators/method on the matrix =====
    // 26. Output matrix
    // void output_matrix();
    // 27. Get value rows
    int& get_rows();
    // 28. Get value columns
    int& get_cols();
    // 29. Get value in matrix
    double get_index_matrix(int i, int j);
    // 30. Set value rows
    void set_rows(int value);
    // 31. Set value columns
    void set_cols(int value);
    // 32. Set value in matrix
    void set_index_matrix(double number, int i, int j);
    // 33. Remove matrix
    void remove_matrix();
};
#endif  // SRC_My_MATRIX_OOP_H__
