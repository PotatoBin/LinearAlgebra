#ifndef MATRIX_H
#define MATRIX_H
#include "Vector.h"

class Matrix {
private:
    int SizeRows, SizeCols;
    std::vector<Vector> matrix;
public:
    Matrix(std::initializer_list<Vector> columns);
    Matrix(int row, int col);
    Matrix(const Matrix& other);
    int GetRowSize() const;
    int GetColSize() const;
    void SetElement(int i, int j, Rational n);
    void SetRowVector(int row, Vector v);
    void SetColVector(int col, Vector v);
    Rational GetElement(int row, int col)const;
    Vector GetRowVector(int row) const;
    Vector GetColVector(int col) const;
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
