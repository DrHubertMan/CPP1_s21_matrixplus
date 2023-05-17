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
  InitMatrix(other.rows_, other.cols_);
  CopyMatrix(other);
  other.FreeMatrix();
}

S21Matrix ::~S21Matrix() { FreeMatrix(); }

void S21Matrix::InitMatrix(const int rows, const int columns) {
  rows_ = rows;
  cols_ = columns;
  matrix_ = new double *[rows_]();
  for (int i = 0; i < rows; ++i) {
    matrix_[i] = new double[cols_]();
  }
}

void S21Matrix::FreeMatrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
    matrix_ = nullptr;
  }
}

bool S21Matrix::EqMatrix(const S21Matrix &other) noexcept {
  bool result = 1;
  if ((rows_ != other.rows_) || (cols_ != other.cols_) ||
      (other.matrix_ == nullptr) || (other.rows_ <= 0) || (other.cols_ <= 0) ||
      (matrix_ == nullptr) || (rows_ <= 0) || (cols_ <= 0)) {
    result = 0;
  } else {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) > S21_EPS) {
          result = 0;
        }
      }
    }
  }
  return result;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (!CompareMatrix(other) || (!ValidMatrix(other) || !ValidMatrix(*this))) {
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
  if (!CompareMatrix(other) || (!ValidMatrix(other) || !ValidMatrix(*this))) {
    throw std::invalid_argument(
        "\nThe number of rows and columns must match\n");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  if (ValidMatrix(*this)) {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        matrix_[i][j] *= num;
      }
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_ || !ValidMatrix(*this) || !ValidMatrix(other)) {
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
  FreeMatrix();
  InitMatrix(rows, other.cols_);
  CopyMatrix(tmpMatrix);
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix resultMatrix(cols_, rows_);
  if (ValidMatrix(*this)) {
    for (int i = 0; i < resultMatrix.rows_; ++i) {
      for (int j = 0; j < resultMatrix.cols_; ++j) {
        resultMatrix.matrix_[i][j] = matrix_[j][i];
      }
    }
  }
  return resultMatrix;
}

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix resultMatrix(rows_, cols_);
  S21Matrix tmpMatrix(rows_ - 1, cols_ - 1);
  if (ValidMatrix(*this) && IsSquare(*this)) {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        tmpMatrix.GetMatrxiMinor(*this, i, j);
        resultMatrix.matrix_[i][j] = tmpMatrix.Determinant() * pow(-1, i + j);
      }
    }
  }
  return resultMatrix;
}

double S21Matrix::Determinant() {
  double result = 1;
  if (IsSquare(*this)) {
    for (int i = 0; i < rows_; ++i) {
      int max_row = i;
      for (int j = i + 1; j < rows_; j++) {
        if (fabs(matrix_[j][i]) > fabs(matrix_[max_row][i])) {
          max_row = j;
        }
      }
      if (i != max_row) {
        double *temp = matrix_[i];
        matrix_[i] = matrix_[max_row];
        matrix_[max_row] = temp;
        result *= -1;
      }
      result *= matrix_[i][i];
      if (result == 0) {
        return 0;
      }
      for (int j = i + 1; j < rows_; j++) {
        double factor = matrix_[j][i] / matrix_[i][i];
        for (int k = i + 1; k < rows_; k++) {
          matrix_[j][k] -= factor * matrix_[i][k];
        }
      }
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  S21Matrix copy(*this);
  double det = copy.Determinant();
  if (rows_ != cols_) {
    throw std::invalid_argument("\nRows and columns must match\n");
  } else if (fabs(det) < S21_EPS) {
    throw std::logic_error("\ndeterminant value can't be equal to 0\n");
  }
  S21Matrix tmpMatrix = CalcComplements();
  S21Matrix tmp = tmpMatrix.Transpose();

  S21Matrix res(tmp);

  res.MulNumber(1 / det);
  return res;
}

void S21Matrix::operator-=(const S21Matrix &other) { SubMatrix(other); }

void S21Matrix::operator+=(const S21Matrix &other) { SumMatrix(other); }

void S21Matrix::operator*=(const S21Matrix &other) { MulMatrix(other); }

void operator*=(S21Matrix &other, double num) { other.MulNumber(num); }

S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  S21Matrix resultMatrix(*this);
  resultMatrix.SumMatrix(other);
  return resultMatrix;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  S21Matrix resultMatrix(*this);
  resultMatrix.SubMatrix(other);
  return resultMatrix;
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (matrix_ == nullptr) {
    CopyMatrix(other);
  } else {
    FreeMatrix();
    InitMatrix(other.rows_, other.cols_);
    CopyMatrix(other);
  }
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  S21Matrix resultMatrix(*this);
  resultMatrix.MulMatrix(other);
  return resultMatrix;
}

S21Matrix operator*(double num, S21Matrix &other) {
  S21Matrix resultMatrix(other);
  resultMatrix.MulNumber(num);
  return resultMatrix;
}

S21Matrix operator*(S21Matrix &other, double num) {
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

bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

int S21Matrix::GetRows() { return rows_; }

int S21Matrix::GetColumns() { return cols_; }

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
  FreeMatrix();
  InitMatrix(rows, cols);
  CopyMatrix(tmpMatrix);
  tmpMatrix.FreeMatrix();
}

void S21Matrix::SetColumns(int columns) {
  if (columns < 1) {
    throw std::invalid_argument("\nRows value can't be less than 1\n");
  }
  S21Matrix tmpMatrix(rows_, columns);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns; ++j) {
      if (j >= cols_) {
        tmpMatrix.matrix_[i][j] = 0.0;
      } else {
        tmpMatrix.matrix_[i][j] = matrix_[i][j];
      }
    }
  }
  int rows = rows_;
  FreeMatrix();
  InitMatrix(rows, columns);
  CopyMatrix(tmpMatrix);
  tmpMatrix.FreeMatrix();
}

void S21Matrix::CopyMatrix(const S21Matrix &other) {
  if (ValidMatrix(other)) {
    for (int i = 0; i < other.rows_; ++i) {
      for (int j = 0; j < other.cols_; ++j) {
        matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
}

bool S21Matrix::CompareMatrix(const S21Matrix &other) {
  return (rows_ == other.rows_ && cols_ == other.cols_) ? 1 : 0;
}

bool S21Matrix::ValidMatrix(const S21Matrix &other) {
  if ((other.matrix_ == nullptr) || (other.rows_ <= 0) || (other.cols_ <= 0)) {
    throw std::invalid_argument("\nWrong value of some class field\n");
  }
  return true;
}

bool S21Matrix::IsSquare(const S21Matrix &other) {
  bool result = (other.rows_ == other.cols_) ? 1 : 0;
  if (!result) {
    throw std::invalid_argument("\nThe matrix must be square\n");
  }
  return result;
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
