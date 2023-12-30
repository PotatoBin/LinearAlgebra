# LinearAlgebra

The `LinearAlgebra` library is a C++ library that extends the functionality of the previously mentioned `Matrix` and `Rational` classes. It offers a wide range of linear algebra operations for matrices and vectors.

## Introduction

The `LinearAlgebra` library is a C++ library created to facilitate the implementation of fundamental linear algebra operations. It is primarily designed for students studying "Contents Mathematics" at Chung-Ang University, College of Art and Technology.

The primary aim of the `LinearAlgebra` library is to provide a practical tool for students, enabling them to perform basic linear algebra calculations in C++. This library is intended to assist with coursework and assignments related to linear algebra, focusing on foundational operations commonly covered in "Contents Mathematics."

## Ongoing Development

Our commitment to providing a valuable resource for students is an ongoing process. We plan to continually expand and improve the library to encompass more functions and features, enhancing its utility for learning and academic projects.

Feel free to explore the library and incorporate it into your studies as you progress through the "Contents Mathematics" course at Chung-Ang University. Your feedback and suggestions for further improvements are highly welcome.


## Functions

Here are some of the additional functions provided by the `LinearAlgebra` library:

- `Matrix pow(const Matrix& m, int e)`: Compute the matrix raised to a power.
- `Matrix inverse2x2(const Matrix& m)`: Calculate the inverse of a 2x2 matrix.
- `Matrix inverse(const Matrix& m)`: Calculate the inverse of a matrix.
- `Matrix diag(const std::initializer_list<Rational> elements)`: Create a diagonal matrix from a list of `Rational` elements.
- `Matrix diag(const std::initializer_list<int> elements)`: Create a diagonal matrix from a list of integer elements.
- `Rational tr(const Matrix& m)`: Calculate the trace of a matrix.
- `Rational sarrusRule(const Matrix& m)`: Compute the determinant using the Sarrus rule.
- `Rational det(const Matrix& m)`: Calculate the determinant of a matrix.
- `Rational cofactor(const Matrix& m, const int a, int b)`: Calculate the cofactor of a matrix.
- `Matrix adj(const Matrix& m)`: Calculate the adjugate (adjoint) of a matrix.
- `Matrix cramerRule(const Matrix& m, const Matrix& b)`: Solve a system of linear equations using Cramer's rule.

## Examples

Here are some examples of how to use the functions from the `LinearAlgebra` library:

```cpp
#include "LinearAlgebra.h"

int main() {
    Matrix A(2, 2, {1, 2, 3, 4});
    Matrix B(2, 2, {5, 6, 7, 8});

    Matrix result_pow = pow(A, 3);
    Matrix result_inverse = inverse2x2(B);

    std::cout << "Matrix A^3:\n" << result_pow << std::endl;
    std::cout << "Inverse of Matrix B:\n" << result_inverse << std::endl;

    return 0;
}
```

# Rational Class

The `Rational` class is a C++ class for representing and performing operations with rational numbers (fractions).

## Introduction

The `Rational` class allows you to work with rational numbers, which are fractions represented by a numerator and a denominator. It provides various mathematical operations on these rational numbers.

## Public Member Functions

- `Rational()`: Default constructor to create a rational number 0/1.
- `Rational(int n)`: Constructor to create a rational number `n/1`.
- `Rational(int n, int d)`: Constructor to create a rational number `n/d`.
- `Rational(const Rational& other)`: Copy constructor to create a rational number from another `Rational` object.
- `bool IsInt() const`: Check if the rational number is an integer.
- `int GetNumer() const`: Get the numerator.
- `int GetDenom() const`: Get the denominator.
- `void SetNumer(int n)`: Set the numerator.
- `void SetDenom(int d)`: Set the denominator.
- `Rational Simplify() const`: Return the simplified (reduced) form of the rational number.
- `Rational Inverse() const`: Calculate the multiplicative inverse (reciprocal) of the rational number.

## Operators Overloaded

- `Rational operator+(const Rational& b) const`: Overloaded `+` operator for addition.
- `Rational operator-(const Rational& b) const`: Overloaded `-` operator for subtraction.
- `Rational operator*(const Rational& b) const`: Overloaded `*` operator for multiplication.
- `Rational operator/(const Rational& b) const`: Overloaded `/` operator for division.
- `bool operator==(const Rational& b) const`: Overloaded `==` operator to check for equality.
- `bool operator!=(const Rational& b) const`: Overloaded `!=` operator to check for inequality.

## Examples

Here are some examples of how to use the `Rational` class:

```cpp
#include "Rational.h"

int main() {
    Rational a(1, 2);
    Rational b(3, 4);

    Rational sum = a + b;
    Rational product = a * b;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << product << std::endl;

    return 0;
}
```

# Matrix Class

The `Matrix` class is a C++ class for representing and performing operations on matrices. It allows you to create, manipulate, and perform various matrix operations, including addition, subtraction, multiplication, and more.

## Introduction

The `Matrix` class provides a versatile and easy-to-use way to work with matrices. You can create matrices of various sizes and perform operations with them, including scalar multiplication and matrix multiplication.

## Public Member Functions

- `Matrix(int numRows, int numCols, std::initializer_list<int> elements)`: Constructor for creating a matrix with integer elements.
- `Matrix(int numRows, int numCols, std::initializer_list<Rational> elements)`: Constructor for creating a matrix with `Rational` elements.
- `Matrix(int numRows, int numCols)`: Constructor for creating an empty matrix.
- `Matrix(int num)`: Constructor for creating a square matrix of size `num` by `num`.
- `Matrix(const Matrix& other)`: Copy constructor to create a matrix from another `Matrix` object.
- `void SetElement(int i, int j, Rational n)`: Set an element in the matrix at position `(i, j)`.
- `Matrix SetRowVector(int r, Matrix v) const`: Set a row vector at row `r`.
- `Matrix SetColVector(int c, Matrix v) const`: Set a column vector at column `c`.
- `int GetRowSize() const`: Get the number of rows in the matrix.
- `int GetColSize() const`: Get the number of columns in the matrix.
- `Rational GetElement(int row, int col) const`: Get an element from the matrix at position `(row, col)`.
- `Matrix GetRowVector(int row) const`: Get a row vector at row `row`.
- `Matrix GetColVector(int col) const`: Get a column vector at column `col`.
- `int FindPivotIndex() const`: Find the pivot index (used in matrix row reduction).
- `Matrix SwapRowVector(int a, int b) const`: Swap two row vectors in the matrix.
- `Matrix SwapColVector(int a, int b) const`: Swap two column vectors in the matrix.
- `Matrix Transpose() const`: Transpose the matrix.
- `bool IsSquare() const`: Check if the matrix is square.
- `bool IsSymmetric() const`: Check if the matrix is symmetric.
- `bool IsSkewSymmetric() const`: Check if the matrix is skew-symmetric.
- `bool IsUpperTriangular() const`: Check if the matrix is upper triangular.
- `bool IsLowerTriangular() const`: Check if the matrix is lower triangular.
- `bool IsTriangular() const`: Check if the matrix is triangular.
- `bool IsDiagonal() const`: Check if the matrix is diagonal.

## Operators Overloaded

- `Matrix operator+(const Matrix& b) const`: Overloaded `+` operator for matrix addition.
- `Matrix operator-(const Matrix& b) const`: Overloaded `-` operator for matrix subtraction.
- `Matrix operator*(const Rational& b) const`: Overloaded `*` operator for scalar multiplication.
- `Matrix operator*(const int& b) const`: Overloaded `*` operator for scalar multiplication with an integer.
- `Matrix operator*(const Matrix& b) const`: Overloaded `*` operator for matrix multiplication.
- `bool operator==(const Matrix& b) const`: Overloaded `==` operator to check for equality.
- `bool operator!=(const Matrix& b) const`: Overloaded `!=` operator to check for inequality.

## Matrix Properties

The class also provides methods to check various properties of the matrix, including whether it's square, symmetric, skew-symmetric, upper triangular, lower triangular, triangular, or diagonal.

## Examples

Here are some examples of how to use the `Matrix` class:

```cpp
#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "Rational.h"

int main() {
    Vector v1{ 1, 2, 3 };
    Vector v2{ 4, 5, 6 };
    Vector v3{ 7, 8, 9 };

    Matrix matrix{ v1, v2, v3 };

    Matrix result_addition = matrix + matrix;
    Matrix result_subtraction = matrix - matrix;
    Matrix result_scalar_multiplication = matrix * 3;

    std::cout << "Matrix Addition:\n" << result_addition << std::endl;
    std::cout << "Matrix Subtraction:\n" << result_subtraction << std::endl;
    std::cout << "Matrix Scalar Multiplication:\n" << result_scalar_multiplication << std::endl;

    return 0;
}
```
