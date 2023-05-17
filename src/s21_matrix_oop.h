#ifndef CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H
#define CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H

#include <cmath>
#include <iostream>

#define S21_EPS 1e-6

class S21Matrix {
 private:
  int rows_;
  int cols_;

  double **matrix_;

  void InitMatrix(const int rows, const int columns);
  void FreeMatrix();
  bool ValidMatrix(const S21Matrix &other);

  void CopyMatrix(const S21Matrix &other);
  bool CompareMatrix(const S21Matrix &other);
  bool IsSquare(const S21Matrix &other);
  S21Matrix GetMatrxiMinor(const S21Matrix &other, int rows, int columns);

 public:
  S21Matrix();
  S21Matrix(int rows, int columns);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();

  bool EqMatrix(const S21Matrix &other) noexcept;

  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);

  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  int GetRows();
  int GetColumns();

  void SetRows(int rows);
  void SetColumns(int columns);

  void operator-=(const S21Matrix &other);
  void operator+=(const S21Matrix &other);

  void operator*=(const S21Matrix &other);
  friend void operator*=(S21Matrix &other, double num);

  S21Matrix operator+(const S21Matrix &other) const;
  S21Matrix operator-(const S21Matrix &other) const;
  S21Matrix &operator=(const S21Matrix &other);

  S21Matrix operator*(const S21Matrix &other) const;
  friend S21Matrix operator*(double num, S21Matrix &other);
  friend S21Matrix operator*(S21Matrix &other, double num);

  double &operator()(int rows, int columns);

  bool operator==(const S21Matrix &other);
};

S21Matrix operator*(double num, S21Matrix &other);
S21Matrix operator*(S21Matrix &other, double num);
void operator*=(S21Matrix &other, double num);

#endif  //  CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H