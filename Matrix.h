#ifndef MATRIX_H
#define MATRIX_H
#include "Rational.h"

class Matrix {
private:
    int SizeRows, SizeCols;
    std::vector<std::vector<Rational>> matrix;
public:
    Matrix(int numRows, int numCols, std::initializer_list<int> elements);
    Matrix(int numRows, int numCols, std::initializer_list<Rational> elements);
    Matrix(int numRows, int numCols);
    Matrix(int num);
    Matrix(const Matrix& other);
    void SetElement(int i, int j, Rational n);
    Matrix SetRowVector(int r, Matrix v) const;
    Matrix SetColVector(int c, Matrix v) const;
    int GetRowSize() const;
    int GetColSize() const;
    Rational GetElement(int row, int col)const;
    Matrix GetRowVector(int row) const;
    Matrix GetColVector(int col) const;
    int FindPivotIndex()const;
    Matrix SwapRowVector(int a, int b)const;
    Matrix SwapColVector(int a, int b)const;
    Matrix Transpose() const;
    bool IsSquare() const;
    bool IsSymmetric() const;
    bool IsSkewSymmetric() const;
    bool IsUpperTriangular() const;
    bool IsLowerTriangular() const;
    bool IsTriangular() const;
    bool IsDiagonal() const;
    Matrix operator+ (const Matrix& b)const;
    Matrix operator- (const Matrix& b)const;
    Matrix operator* (const Rational& b)const;
    Matrix operator* (const int& b)const;
    Matrix operator* (const Matrix& b)const;
    bool operator==(const Matrix& b)const;
    bool operator!=(const Matrix& b)const;
};
std::ostream& operator<<(std::ostream& os, const Matrix& b);
#endif // MATRIX_H
