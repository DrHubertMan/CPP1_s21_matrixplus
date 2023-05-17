#ifndef CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H
#define CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H

#include <cmath>
#include <iostream>

#define S21_EPS 1e-6

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int columns);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();

  bool EqMatrix(const S21Matrix &other) noexcept;

  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix &other);

  S21Matrix Transpose() const noexcept;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  int GetRows() const noexcept;
  int GetColumns() const noexcept;

  void SetRows(int rows);
  void SetColumns(int columns);

  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator+=(const S21Matrix &other);

  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(double num) noexcept;

  S21Matrix operator+(const S21Matrix &other) const noexcept;
  S21Matrix operator-(const S21Matrix &other) const noexcept;
  S21Matrix &operator=(const S21Matrix &other) noexcept;

  S21Matrix operator*(const S21Matrix &other) const noexcept;
  friend S21Matrix operator*(double num, S21Matrix &other) noexcept;
  friend S21Matrix operator*(S21Matrix &other, double num) noexcept;

  double &operator()(int rows, int columns);

  bool operator==(const S21Matrix &other);

 private:
  int rows_;
  int cols_;

  double **matrix_;

  void InitMatrix(const int rows, const int columns) noexcept;

  void CopyMatrix(const S21Matrix &other) noexcept;
  bool CompareMatrix(const S21Matrix &other) const noexcept;
  S21Matrix GetMatrxiMinor(const S21Matrix &other, int rows, int columns);
};

#endif  //  CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H