#include "matrix.h"
namespace Maze {
/* ---------- Constructors & Destructor ---------- */

MazeMatrix::MazeMatrix() {
    rows_ = 0;
    cols_ = 0;
    matrix_ = nullptr;
}

MazeMatrix::MazeMatrix(int rows, int cols) : rows_(rows), cols_(cols) {
    if (rows_ < 0 || cols_ < 0)
        throw std::out_of_range("Rows or Columns cannot be less 0");
    if (rows_ == 0 || cols_ == 0)
        matrix_ = nullptr;
    else
        memory_allocation();
}

MazeMatrix::MazeMatrix(int rows, int cols, const double data_massive[]) {
    rows_ = rows;
    cols_ = cols;
    if (rows_ < 0 || cols_ < 0 || data_massive == nullptr)
        throw std::out_of_range("Rows or Columns cannot be less 0");
    if (rows_ == 0 || cols_ == 0) {
        matrix_ = nullptr;
    } else {
        memory_allocation();
        for (int i = 0; i < rows_; i++) {
            for (int k = 0; k < cols_; k++)
                matrix_[i][k] = data_massive[i * cols_ + k];
        }
    }
}

MazeMatrix::MazeMatrix(const MazeMatrix &other) : MazeMatrix() {
    *this = other;
}

MazeMatrix::MazeMatrix(MazeMatrix &&other) : MazeMatrix() {
    *this = std::move(other);
}
MazeMatrix::~MazeMatrix() { memory_free(); }

void MazeMatrix::memory_allocation() {
    matrix_ = new double *[rows_];
    for (int i = 0; i < rows_; i++) matrix_[i] = new double[cols_]{0};
}

void MazeMatrix::memory_free() {
    if (matrix_) {
        for (int i = 0; i < rows_; i++) {
            if (matrix_[i]) {
                delete[] matrix_[i];
                matrix_[i] = nullptr;
            }
        }
        delete[] matrix_;
        matrix_ = nullptr;
    }
    rows_ = 0;
    cols_ = 0;
}

/* ---------- Help Methods ---------- */

void MazeMatrix::output_matrix() {
    if (matrix_) {
        std::cout << "Matrix output:" << std::endl;
        for (int i = 0; i < rows_; i++) {
            for (int k = 0; k < cols_; k++)
                std::cout << std::fixed << std::setprecision(7) << matrix_[i][k]
                          << " | ";
            if (i < (rows_ - 1)) std::cout << std::endl;
        }
        std::cout << std::endl;
    } else {
        throw std::out_of_range("Matrix is empty");
    }
}

/* ---------- Task General Methods ---------- */

bool MazeMatrix::eq_matrix(const MazeMatrix &other) {
    bool Result = true;
    if (rows_ == other.rows_ && cols_ == other.cols_) {
        double tolerance = 1e-7;
        for (int i = 0; i < rows_; i++) {
            for (int k = 0; k < cols_; k++) {
                if (fabs(matrix_[i][k] - other.matrix_[i][k]) >= tolerance)
                    Result = false;
            }
        }
    } else {
        Result = false;
    }
    return Result;
}

void MazeMatrix::sum_matrix(const MazeMatrix &other) {
    if (rows_ != other.rows_ || cols_ != other.cols_)
        throw std::out_of_range(
            "Matrixes with different size cannot be summed");
    for (int i = 0; i < rows_; i++) {
        for (int k = 0; k < cols_; k++)
            matrix_[i][k] = matrix_[i][k] + other.matrix_[i][k];
    }
}

void MazeMatrix::sub_matrix(const MazeMatrix &other) {
    if (rows_ != other.rows_ || cols_ != other.cols_)
        throw std::out_of_range(
            "Matrixes with different size cannot be subtracted");
    for (int i = 0; i < rows_; i++) {
        for (int k = 0; k < cols_; k++)
            matrix_[i][k] = matrix_[i][k] - other.matrix_[i][k];
    }
}

void MazeMatrix::mul_number(const double num) {
    for (int i = 0; i < rows_; i++) {
        for (int k = 0; k < cols_; k++) {
            if (matrix_[i][k] != 0) matrix_[i][k] = matrix_[i][k] * num;
        }
    }
}

void MazeMatrix::mul_matrix(const MazeMatrix &other) {
    if (cols_ != other.rows_)
        throw std::out_of_range(
            "Matrixes cannot be multed: matrix_1 cols != matrix_2 rows.");
    MazeMatrix Result(rows_, other.cols_);
    for (int i = 0; i < rows_; i++) {
        for (int k = 0; k < other.cols_; k++) {
            double summatrix__elements = 0.0;
            for (int j = 0; j < cols_; j++)
                summatrix__elements += matrix_[i][j] * other.matrix_[j][k];
            Result.matrix_[i][k] = summatrix__elements;
        }
    }
    memory_free();
    rows_ = Result.rows_;
    cols_ = Result.cols_;
    memory_allocation();
    for (int i = 0; i < rows_; i++) {
        for (int k = 0; k < cols_; k++) matrix_[i][k] = Result.matrix_[i][k];
    }
}

MazeMatrix MazeMatrix::transpose() {
    MazeMatrix Result(cols_, rows_);
    for (int i = 0; i < Result.rows_; i++) {
        for (int k = 0; k < Result.cols_; k++)
            Result.matrix_[i][k] = matrix_[k][i];
    }
    return Result;
}

double MazeMatrix::determinant() {
    if (rows_ != cols_)
        throw std::out_of_range(
            "Determinant cannot be found: matrix isn't square.");
    else if (rows_ == 0)
        throw std::out_of_range(
            "Determinant cannot be found: matrix is empty.");
    double Result;
    if (rows_ == 1) {
        Result = matrix_[0][0];
    } else {
        double sum_of_koef = 0.0;
        for (int k = 0; k < cols_; k++) {
            int tmp_matrix_size = cols_ - 1;
            MazeMatrix tmp_matrix = create_minor_matrix(tmp_matrix_size, 0, k);
            sum_of_koef +=
                matrix_[0][k] * pow(-1, (1 + k + 1)) * tmp_matrix.determinant();
        }
        Result = sum_of_koef;
    }
    return Result;
}

MazeMatrix MazeMatrix::create_minor_matrix(int size, int rows_index,
                                           int cols_index) {
    MazeMatrix Result(size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j >= cols_index && i >= rows_index)
                Result.matrix_[i][j] = matrix_[i + 1][j + 1];
            else if (j >= cols_index && i < rows_index)
                Result.matrix_[i][j] = matrix_[i][j + 1];
            else if (j < cols_index && i >= rows_index)
                Result.matrix_[i][j] = matrix_[i + 1][j];
            else
                Result.matrix_[i][j] = matrix_[i][j];
        }
    }
    return Result;
}

MazeMatrix MazeMatrix::calc_complements() {
    if (rows_ != cols_)
        throw std::out_of_range(
            "Сofactor matrix cannot be found: matrix isn't square.");
    MazeMatrix Result(rows_, cols_);
    if (rows_ == 1) {
        Result.matrix_[0][0] = 1;
    } else {
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++) {
                int tmp_matrix_size = cols_ - 1;
                MazeMatrix tmp_matrix =
                    create_minor_matrix(tmp_matrix_size, i, j);
                Result.matrix_[i][j] =
                    pow(-1, (i + 1 + j + 1)) * tmp_matrix.determinant();
            }
        }
    }
    return Result;
}

MazeMatrix MazeMatrix::inverse_matrix() {
    double det = determinant();
    if (det == 0)
        throw std::out_of_range(
            "Inverse matrix cannot be found: det is nought.");
    MazeMatrix Tmp_cofactormatrix_ = calc_complements();
    MazeMatrix Tmp_transposematrix_ = Tmp_cofactormatrix_.transpose();
    Tmp_transposematrix_.mul_number(1 / det);
    MazeMatrix Result(rows_, cols_);
    for (int i = 0; i < rows_; i++) {
        for (int k = 0; k < cols_; k++)
            Result.matrix_[i][k] = Tmp_transposematrix_.matrix_[i][k];
    }
    return Result;
}

/* ---------- Accessor and Mutator Methods ---------- */
int MazeMatrix::get_rows() { return rows_; }
int MazeMatrix::get_cols() { return cols_; }
void MazeMatrix::set_rows(int value_rows) {
    if (value_rows < 0)
        throw std::out_of_range("Rows or Columns cannot be less 0");
    if (value_rows == 0) {
        memory_free();
    } else if (rows_ != value_rows) {
        MazeMatrix old_matrix = (*this);
        int save_cols = cols_;
        memory_free();
        rows_ = value_rows;
        cols_ = save_cols;
        memory_allocation();
        for (int i = 0; i < rows_; i++) {
            for (int k = 0; k < cols_; k++) {
                if (i >= old_matrix.rows_ || k >= old_matrix.cols_)
                    matrix_[i][k] = 0;
                else
                    matrix_[i][k] = old_matrix.matrix_[i][k];
            }
        }
    }
}

void MazeMatrix::set_cols(int value_cols) {
    if (value_cols < 0)
        throw std::out_of_range("Rows or Columns cannot be less 0");
    if (value_cols == 0) {
        memory_free();
    } else if (cols_ != value_cols) {
        MazeMatrix old_matrix = (*this);
        int save_rows = rows_;
        memory_free();
        rows_ = save_rows;
        cols_ = value_cols;
        memory_allocation();
        for (int i = 0; i < rows_; i++) {
            for (int k = 0; k < cols_; k++) {
                if (i >= old_matrix.rows_ || k >= old_matrix.cols_)
                    matrix_[i][k] = 0;
                else
                    matrix_[i][k] = old_matrix.matrix_[i][k];
            }
        }
    }
}

double **MazeMatrix::get_matrix() { return matrix_; }

/* ---------- Operators overloading ---------- */
MazeMatrix MazeMatrix::operator+(const MazeMatrix &other) {
    MazeMatrix Result = *this;
    Result.sum_matrix(other);
    return Result;
}

MazeMatrix MazeMatrix::operator-(const MazeMatrix &other) {
    MazeMatrix Result = *this;
    Result.sub_matrix(other);
    return Result;
}

MazeMatrix MazeMatrix::operator*(const MazeMatrix &other) {
    MazeMatrix Result = *this;
    Result.mul_matrix(other);
    return Result;
}

MazeMatrix operator*(const double num, const MazeMatrix &matrix) {
    MazeMatrix Result(matrix.rows_, matrix.cols_);
    for (int i = 0; i < matrix.rows_; i++) {
        for (int k = 0; k < matrix.cols_; k++) {
            if (matrix.matrix_[i][k] == 0)
                Result.matrix_[i][k] = matrix.matrix_[i][k];
            else
                Result.matrix_[i][k] = num * matrix.matrix_[i][k];
        }
    }
    return Result;
}

MazeMatrix operator*(const MazeMatrix &matrix, const double num) {
    MazeMatrix Result(matrix.rows_, matrix.cols_);
    for (int i = 0; i < matrix.rows_; i++) {
        for (int k = 0; k < matrix.cols_; k++) {
            if (matrix.matrix_[i][k] == 0)
                Result.matrix_[i][k] = matrix.matrix_[i][k];
            else
                Result.matrix_[i][k] = num * matrix.matrix_[i][k];
        }
    }
    return Result;
}

bool MazeMatrix::operator==(const MazeMatrix &other) {
    bool Result = eq_matrix(other);
    return Result;
}

MazeMatrix &MazeMatrix::operator=(const MazeMatrix &other) {
    if (this == &other)
        throw std::out_of_range("Coping the same list is forbidden!");
    memory_free();
    rows_ = other.rows_;
    cols_ = other.cols_;
    memory_allocation();
    for (int i = 0; i < rows_; i++)
        for (int k = 0; k < cols_; k++) matrix_[i][k] = other.matrix_[i][k];
    return *this;
}

MazeMatrix &MazeMatrix::operator=(MazeMatrix &&other) {
    if (this == &other)
        throw std::out_of_range("Moving the same list is forbidden!");
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
    return *this;
}

MazeMatrix &MazeMatrix::operator+=(const MazeMatrix &other) {
    sum_matrix(other);
    return *this;
}

MazeMatrix &MazeMatrix::operator-=(const MazeMatrix &other) {
    sub_matrix(other);
    return *this;
}

MazeMatrix &MazeMatrix::operator*=(const MazeMatrix &other) {
    mul_matrix(other);
    return *this;
}

MazeMatrix &MazeMatrix::operator*=(const double num) {
    mul_number(num);
    return *this;
}

double &MazeMatrix::operator()(int i, int j) {
    if (i < 0 || j < 0)
        throw std::out_of_range(
            "Wrong value of index! Indexes cannot be less 0");
    if (i > (rows_ - 1) || j > (cols_ - 1))
        throw std::out_of_range(
            "Wrong value of index! Value exceeds the size of the matrix.");
    return this->matrix_[i][j];
}

void MazeMatrix::set_index_matrix(int number, int i, int j) {
    if (i < 0 || j < 0)
        throw std::out_of_range(
            "Wrong value of index! Indexes cannot be less 0");
    if (i > (rows_ - 1) || j > (cols_ - 1))
        throw std::out_of_range(
            "Wrong value of index! Value exceeds the size of the matrix.");
    matrix_[i][j] = number;
}

int MazeMatrix::get_index_matrix(int i, int j) { return matrix_[i][j]; }

void MazeMatrix::clear() { memory_free(); }
}  // namespace Maze
