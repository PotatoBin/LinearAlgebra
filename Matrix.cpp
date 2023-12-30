#include "Matrix.h"

Matrix::Matrix(std::initializer_list<Vector> columns) : SizeCols(static_cast<int>(columns.size())), SizeRows(0) {
    if (SizeCols > 0) {
        SizeRows = columns.begin()->GetSize();
        matrix.reserve(SizeCols);

        for (const auto& col : columns) {
            if (col.GetSize() != SizeRows) {
                throw std::invalid_argument("All columns must have the same size");
            }
            matrix.push_back(col);
        }
    } else {
        throw std::invalid_argument("Matrix initializer list cannot be empty");
    }
}

Matrix::Matrix(int row, int col) : SizeRows(row), SizeCols(col) {
    if (row <= 0 || col <= 0) {
        throw std::invalid_argument("Row and column size must be positive integers");
    }

    matrix.resize(row, Vector(col));
}

Matrix::Matrix(const Matrix& other) : SizeRows(other.SizeRows), SizeCols(other.SizeCols) {}

int Matrix::GetRowSize() const {
    return SizeRows;
}

int Matrix::GetColSize() const {
    return SizeCols;
}

void Matrix::SetElement(int row, int col, Rational n) {
    if (row <= 0 || row > GetRowSize() || col <= 0 || col > GetColSize()) {
        throw std::out_of_range("Invalid row or column index");
    }
    matrix[col - 1].SetElement(row, n);
}

void Matrix::SetRowVector(int row, Vector v) {
    if (row <= 0 || row > GetRowSize() || v.GetSize() != GetColSize()) {
        throw std::invalid_argument("Invalid row or column size");
    }
    for (int i = 1; i <= GetColSize(); ++i) {
        SetElement(row, i, v.GetElement(i));
    }
}

void Matrix::SetColVector(int col, Vector v) {
    if (col <= 0 || col > GetColSize() || v.GetSize() != GetRowSize()) {
        throw std::invalid_argument("Invalid row or column size");
    }
    matrix[col - 1] = v;
}


Rational Matrix::GetElement(int row, int col) const{
    if (row < 1 || row > GetRowSize() || col < 1 || col > GetColSize()) {
        throw std::out_of_range("Invalid row or column index");
    }
    return GetRowVector(row).GetElement(col);
}

Vector Matrix::GetRowVector(int row) const{
    if (row < 1 || row > GetRowSize()){
        throw std::out_of_range("Invalid row number");
    }
    return matrix[row-1];
}

Vector Matrix::GetColVector(int col) const{
    if (col < 1 || col > GetColSize()){
        throw std::out_of_range("Invalid column number");
    }
    Vector v(GetRowSize());
    for(int i=1;i<=GetRowSize();++i){
        v.SetElement(i, GetElement(i, col));
    }
    return v;
}

Matrix Matrix::Transpose() const{
    Matrix result(GetColSize(), GetRowSize());
    for (int i=1;i<=GetColSize();++i){
        for (int j=1;j<=GetRowSize();++j){
            result.SetElement(i, j, GetElement(j, i));
        }
    }
    return result;
}

bool Matrix::IsSquare() const{ return GetRowSize() == GetColSize();}

bool Matrix::IsSymmetric() const{
    return *this == Transpose();
}

bool Matrix::IsSkewSymmetric() const{
    return *this * -1 == Transpose();
}

bool Matrix::IsUpperTriangular() const{
    for(int i=1;i<=GetRowSize();++i){
        for(int j=1;j<=GetColSize();++j){
            if (i > j && GetElement(i, j) != Rational()) return false;
        }
    }
    return true;
}

bool Matrix::IsLowerTriangular() const{
    for(int i=1;i<=GetRowSize();++i){
        for(int j=1;j<=GetColSize();++j){
            if (i < j && GetElement(i, j) != Rational()) return false;
        }
    }
    return true;
}

bool Matrix::IsTriangular() const { return (IsUpperTriangular() || IsLowerTriangular()); }

bool Matrix::IsDiagonal() const{return (IsUpperTriangular() && IsLowerTriangular());}

Matrix Matrix::operator+(const Matrix& b) const {
    int rows = GetRowSize();
    int cols = GetColSize();
    if (rows != b.GetRowSize() || cols != b.GetColSize()) {
        throw std::invalid_argument("ERROR: Matrices must have the same dimensions for addition");
    }
    Matrix result(rows, cols);
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            result.SetElement(i, j, GetElement(i, j) + b.GetElement(i, j));
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& b) const {
    int rows = GetRowSize();
    int cols = GetColSize();
    if (rows != b.GetRowSize() || cols != b.GetColSize()) {
        throw std::invalid_argument("ERROR: Matrices must have the same dimensions for subtraction");
    }
    Matrix result(rows, cols);
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            result.SetElement(i, j, GetElement(i, j) - b.GetElement(i, j));
        }
    }
    return result;
}


Matrix Matrix::operator* (const Rational& b)const{
    int rows = GetRowSize();
    int cols = GetColSize();
    Matrix result(rows,cols);
    for (int i=1;i<=rows;i++){
        for (int j=1;j<=cols;j++){
            result.SetElement(i,j, GetElement(i, j) * b);
        }
    }
    return result;
}

Matrix Matrix::operator* (const int& b)const{
    int rows = GetRowSize();
    int cols = GetColSize();
    Matrix result(rows,cols);
    for (int i=1;i<=rows;i++){
        for (int j=1;j<=cols;j++){
            result.SetElement(i,j, GetElement(i, j) * Rational(b));
        }
    }
    return result;
}

Matrix Matrix::operator* (const Matrix& b)const{
    int rowsA = GetRowSize();
    int colsA = GetColSize();
    int rowsB = b.GetRowSize();
    int colsB = b.GetColSize();
    if (colsA != rowsB) {
        throw std::runtime_error("ERROR: UNCALCULATED MATRIX PAIR");
    }
    Matrix result(rowsA, colsB);
    for (int i = 1; i <= rowsA; i++) {
        for (int j = 1; j <= colsB; j++) {
            for (int k = 1; k <= colsA; k++){
                result.SetElement(i,j, result.GetElement(i,j) + (GetElement(i, k) * b.GetElement(k, j)));
            }
        }
    }

    return result;
}

bool Matrix::operator==(const Matrix& b)const{
    if(GetRowSize() != b.GetRowSize() || GetColSize() != b.GetColSize()) return false;
    for (int i=1;i<=GetRowSize();++i){
        for (int j=1;j<=GetColSize();++j){
            if (GetElement(i, j) != b.GetElement(i, j)) return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& b)const{
    if(GetRowSize() != b.GetRowSize() || GetColSize() != b.GetColSize()) return true;
    for (int i=1;i<=GetRowSize();++i){
        for (int j=1;j<=GetColSize();++j){
            if (GetElement(i, j) != b.GetElement(i, j)) return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Matrix& b) {
    for (int i = 1; i <= b.GetRowSize(); ++i) {
        os << b.GetRowVector(i) << std::endl;
    }
    return os;
}
