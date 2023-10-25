#include "Matrix.h"

Matrix::Matrix(int numRows, int numCols, std::initializer_list<int> elements) : SizeRows(numRows), SizeCols(numCols) {
    matrix.resize(numRows, std::vector<Rational>(numCols));
    const int* iter = elements.begin();
    for (int i = 1; i <= numRows; ++i) {
        for (int j = 1; j <= numCols; ++j) {
            if (iter != elements.end()) {
                SetElement(i, j, Rational(*iter));
                ++iter;
            } else {
                std::runtime_error("ERROR: INSUFFICIENT ELEMENTS FOR THE MATRIX");
            }
        }
    }
    if (iter != elements.end()) {
        throw std::runtime_error("ERROR: EXCESS ELEMENTS FOR THE MATRIX");
    }
}

Matrix::Matrix(int numRows, int numCols, std::initializer_list<Rational> elements) : SizeRows(numRows), SizeCols(numCols) {
    matrix.resize(numRows, std::vector<Rational>(numCols));
    const Rational* iter = elements.begin();
    for (int i = 1; i <= numRows; ++i) {
        for (int j = 1; j <= numCols; ++j) {
            if (iter != elements.end()) {
                SetElement(i, j, *iter);
                ++iter;
            } else {
                std::runtime_error("ERROR: INSUFFICIENT ELEMENTS FOR THE MATRIX");
            }
        }
    }
    if (iter != elements.end()) {
        throw std::runtime_error("ERROR: EXCESS ELEMENTS FOR THE MATRIX");
    }
}

Matrix::Matrix(int numRows, int numCols) : SizeRows(numRows), SizeCols(numCols) {
    matrix.resize(numRows, std::vector<Rational>(numCols));
    for (int i = 1; i <= numRows; ++i) {
        for (int j = 1; j <= numCols; ++j) {
            SetElement(i,j, Rational());
        }
    }
    
}

Matrix::Matrix(int num) : SizeRows(num), SizeCols(num){
    matrix.resize(num, std::vector<Rational>(num));
    
    for (int i = 1; i <= num; ++i) {
        for (int j = 1; j <= num; ++j) {
            if(i==j)
                SetElement(i,j,Rational(1));
            else
                SetElement(i,j, Rational());
        }
    }
}

Matrix::Matrix(const Matrix& other) : SizeRows(other.SizeRows), SizeCols(other.SizeCols) {
    matrix.resize(SizeRows, std::vector<Rational>(SizeCols));
    for (int i = 1; i <= GetRowSize(); i++) {
        for (int j = 1; j <= GetColSize(); j++) {
            SetElement(i,j, other.GetElement(i, j));
        }
    }
}

void Matrix::SetElement(int row, int col, Rational n){
    matrix[row-1][col-1] = n;
}

Matrix Matrix::SetRowVector(int r, Matrix v) const{
    if(v.GetColSize() != GetColSize()){
        throw std::runtime_error("ERROR: MATRIX OF DIFFERENT SIZES");
    }
    if(v.GetRowSize() != 1){
        throw std::runtime_error("ERROR: THE MATRIX OF ARGUMENT IS NOT A VECTOR");
    }
    Matrix result(*this);
    for(int i=1;i<=GetColSize();++i){
        result.SetElement(r, i, v.GetElement(1, i));
    }
    return result;
}

Matrix Matrix::SetColVector(int c, Matrix v) const{
    if(v.GetRowSize() != GetRowSize()){
        throw std::runtime_error("ERROR: MATRIX OF DIFFERENT SIZES");
    }
    if(v.GetColSize() != 1){
        throw std::runtime_error("ERROR: THE MATRIX OF ARGUMENT IS NOT A VECTOR");
    }
    Matrix result(*this);
    for(int i=1;i<=GetRowSize();++i){
        result.SetElement(i, c, v.GetElement(i, 1));
    }
    return result;
}

int Matrix::GetRowSize() const {
    return SizeRows;
}

int Matrix::GetColSize() const {
    return SizeCols;
    
}

Rational Matrix::GetElement(int row, int col) const{
    if (row < 1 || row > GetRowSize() || col < 1 || col > GetColSize()) {
        throw std::runtime_error("ERROR: INDEX OUT OF RANGE");
    }
    return matrix[row-1][col-1];
}

Matrix Matrix::GetRowVector(int row) const{
    if (row < 1 || row > GetRowSize()){
        throw std::runtime_error("ERROR: INVALID ROW NUMBER");
    }
    Matrix RowVector(1, GetColSize());
    for (int i=1;i<=GetColSize();++i){
        RowVector.SetElement(1,i, GetElement(row, i));
    }
    return RowVector;
}

Matrix Matrix::GetColVector(int col) const{
    if (col < 1 || col > GetColSize()){
        throw std::runtime_error("ERROR: INVALID COLUMN NUMBER");
    }
    Matrix ColVector(GetRowSize(), 1);
    for (int i=1;i<=GetRowSize();++i){
        ColVector.SetElement(i, 1, GetElement(i, col));
    }
    return ColVector;
}

int Matrix::FindPivotIndex()const{
    int i = 0;
    while (GetElement(1, i)==0){
        ++i;
    }
    return i;
}

Matrix Matrix::SwapRowVector(int a, int b)const{
    Matrix VectorA = GetRowVector(a);
    Matrix VectorB = GetRowVector(b);
    Matrix result(*this);
    result.SetRowVector(b, VectorA);
    result.SetRowVector(a, VectorB);
    return result;
}

Matrix Matrix::SwapColVector(int a, int b)const{
    Matrix VectorA = GetColVector(a);
    Matrix VectorB = GetColVector(b);
    Matrix result(*this);
    result.SetColVector(b, VectorA);
    result.SetColVector(a, VectorB);
    return result;
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
        for(int j=1;j<=GetColSize();++i){
            if (i>j && GetElement(i, j) != Rational()) return false;
        }
    }
    return true;
}

bool Matrix::IsLowerTriangular() const{
    for(int i=1;i<=GetRowSize();++i){
        for(int j=1;j<=GetColSize();++i){
            if (i<j && GetElement(i, j) != Rational()) return false;
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
        throw std::runtime_error("ERROR: MATRIX OF DIFFERENT SIZES");
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
        throw std::runtime_error("ERROR: MATRIX OF DIFFERENT SIZES");
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

std::ostream& operator<<(std::ostream& os, const Matrix& b){
    for (int i = 1; i <= b.GetRowSize(); ++i) {
        os << "[" ;
        for (int j = 1; j <= b.GetColSize(); ++j) {
            os << " ";
            os << b.GetElement(i, j);
            os << " ";
        }
        os << "]" << std::endl;
    }
    return  os;
}
