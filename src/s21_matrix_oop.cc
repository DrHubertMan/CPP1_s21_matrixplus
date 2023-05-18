#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(1), cols_(1) { InitMatrix(rows_, cols_); }

S21Matrix::S21Matrix(int rows, int columns) {
  if (rows < 1 || columns < 1) {
    throw std::bad_array_new_length();
  }
  InitMatrix(rows, columns);
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  InitMatrix(other.rows_, other.cols_);
  CopyMatrix(other);
}

S21Matrix::S21Matrix(S21Matrix &&other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

S21Matrix ::~S21Matrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
    matrix_ = nullptr;
  };
}

void S21Matrix::InitMatrix(const int rows, const int columns) noexcept {
  rows_ = rows;
  cols_ = columns;
  matrix_ = new double *[rows_]();
  for (int i = 0; i < rows; ++i) {
    matrix_[i] = new double[cols_]();
  }
}

bool S21Matrix::EqMatrix(const S21Matrix &other) noexcept {
  bool result = 1;
  if ((rows_ != other.rows_) || (cols_ != other.cols_)) {
    result = 0;
  } else {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        if (std::fabs(matrix_[i][j] - other.matrix_[i][j]) > S21_EPS) {
          result = 0;
        }
      }
    }
  }
  return result;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (!CompareMatrix(other)) {
    throw std::invalid_argument(
        "\nThe number of rows and columns must match\n");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (!CompareMatrix(other)) {
    throw std::invalid_argument(
        "\nThe number of rows and columns must match\n");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument("\nWrong count of rows or columns\n");
  }
  int rows = rows_;
  int columns = other.cols_;
  S21Matrix tmpMatrix(rows, columns);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      for (int k = 0; k < cols_; ++k) {
        tmpMatrix.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = std::move(tmpMatrix);
}

S21Matrix S21Matrix::Transpose() const noexcept {
  S21Matrix resultMatrix(cols_, rows_);
  for (int i = 0; i < resultMatrix.rows_; ++i) {
    for (int j = 0; j < resultMatrix.cols_; ++j) {
      resultMatrix.matrix_[i][j] = matrix_[j][i];
    }
  }
  return resultMatrix;
}

S21Matrix S21Matrix::CalcComplements() const {
  S21Matrix resultMatrix(rows_, cols_);
  S21Matrix tmpMatrix(rows_ - 1, cols_ - 1);
  if (rows_ != cols_) {
    throw std::invalid_argument("\nThe matrix must be square\n");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      tmpMatrix.GetMatrxiMinor(*this, i, j);
      resultMatrix.matrix_[i][j] = tmpMatrix.Determinant() * pow(-1, i + j);
    }
  }
  return resultMatrix;
}

double S21Matrix::Determinant() const {
  double result = 1;
  S21Matrix tmp(*this);
  if (rows_ != cols_) {
    throw std::invalid_argument("\nThe matrix must be square\n");
  }
  for (int i = 0; i < rows_; ++i) {
    int max_row = i;
    for (int j = i + 1; j < rows_; j++) {
      if (std::fabs(tmp.matrix_[j][i]) > std::fabs(tmp.matrix_[max_row][i])) {
        max_row = j;
      }
    }
    if (i != max_row) {
      double *temp = tmp.matrix_[i];
      tmp.matrix_[i] = tmp.matrix_[max_row];
      tmp.matrix_[max_row] = temp;
      result *= -1;
    }
    result *= tmp.matrix_[i][i];
    if (result == 0) {
      return 0;
    }
    for (int j = i + 1; j < rows_; j++) {
      double factor = tmp.matrix_[j][i] / tmp.matrix_[i][i];
      for (int k = i + 1; k < rows_; k++) {
        tmp.matrix_[j][k] -= factor * tmp.matrix_[i][k];
      }
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() const {
  S21Matrix copy(*this);
  double det = copy.Determinant();
  if (copy.rows_ != copy.cols_) {
    throw std::invalid_argument("\nRows and columns must match\n");
  } else if (std::fabs(det) < S21_EPS) {
    throw std::logic_error("\ndeterminant value can't be equal to 0\n");
  }
  S21Matrix tmpMatrix = CalcComplements();
  S21Matrix tmp = tmpMatrix.Transpose();

  S21Matrix res(tmp);

  res.MulNumber(1 / det);
  return res;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(double num) noexcept {
  MulNumber(num);
  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) const noexcept {
  S21Matrix resultMatrix(*this);
  resultMatrix.SumMatrix(other);
  return resultMatrix;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) const noexcept {
  S21Matrix resultMatrix(*this);
  resultMatrix.SubMatrix(other);
  return resultMatrix;
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) noexcept {
  this->~S21Matrix();
  InitMatrix(other.rows_, other.cols_);
  CopyMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const noexcept {
  S21Matrix resultMatrix(*this);
  resultMatrix.MulMatrix(other);
  return resultMatrix;
}

S21Matrix operator*(double num, S21Matrix &other) noexcept {
  S21Matrix resultMatrix(other);
  resultMatrix.MulNumber(num);
  return resultMatrix;
}

S21Matrix operator*(S21Matrix &other, double num) noexcept {
  S21Matrix resultMatrix(other);
  resultMatrix.MulNumber(num);
  return resultMatrix;
}

double &S21Matrix::operator()(int rows, int columns) {
  if (rows >= rows_ || columns >= cols_) {
    throw std::invalid_argument("\nIndex out of range\n");
  }
  return matrix_[rows][columns];
}

bool S21Matrix::operator==(const S21Matrix &other) noexcept {
  return EqMatrix(other);
}

int S21Matrix::GetRows() const noexcept { return rows_; }

int S21Matrix::GetColumns() const noexcept { return cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows < 1) {
    throw std::invalid_argument("\nRows value can't be less than 1\n");
  }
  S21Matrix tmpMatrix(rows, cols_);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (i >= rows_) {
        tmpMatrix.matrix_[i][j] = 0.0;
      } else {
        tmpMatrix.matrix_[i][j] = matrix_[i][j];
      }
    }
  }
  int cols = cols_;
  this->~S21Matrix();
  InitMatrix(rows, cols);
  CopyMatrix(tmpMatrix);
  tmpMatrix.~S21Matrix();
}

void S21Matrix::SetColumns(int columns) {
  if (columns < 1) {
    throw std::invalid_argument("\nRows value can't be less than 1\n");
  }
  S21Matrix tmpMatrix(rows_, columns);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns; ++j) {
      if (j >= cols_) {
        continue;
      } else {
        tmpMatrix.matrix_[i][j] = matrix_[i][j];
      }
    }
  }
  int rows = rows_;
  this->~S21Matrix();
  InitMatrix(rows, columns);
  CopyMatrix(tmpMatrix);
  tmpMatrix.~S21Matrix();
}

void S21Matrix::CopyMatrix(const S21Matrix &other) noexcept {
  for (int i = 0; i < other.rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

bool S21Matrix::CompareMatrix(const S21Matrix &other) const noexcept {
  return (rows_ == other.rows_ && cols_ == other.cols_) ? 1 : 0;
}

S21Matrix S21Matrix::GetMatrxiMinor(const S21Matrix &other, int rows,
                                    int columns) {
  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      if (i != rows && j != columns) {
        if (j > columns && i > rows) {
          matrix_[i - 1][j - 1] = other.matrix_[i][j];
        } else if (j < columns && i < rows) {
          matrix_[i][j] = other.matrix_[i][j];
        } else if (j > columns && i < rows) {
          matrix_[i][j - 1] = other.matrix_[i][j];
        } else if (j < columns && i > rows) {
          matrix_[i - 1][j] = other.matrix_[i][j];
        }
      }
    }
  }
  return *this;
}
