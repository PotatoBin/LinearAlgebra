#ifndef LinearAlgebra_h
#define LinearAlgebra_h
#include "Rational.h"
#include "Matrix.h"

Matrix pow (const Matrix& m, int e);

Matrix inverse2x2 (const Matrix& m);
Matrix inverse (const Matrix& m);
Matrix diag(const std::initializer_list<Rational> elements);
Matrix diag(const std::initializer_list<int> elements);
Rational tr(const Matrix& m);
Rational sarrusRule(const Matrix& m);
Rational det(const Matrix& m);
Rational cofactor(const Matrix& m, const int a, int b);
Matrix adj(const Matrix& m);
Matrix cramerRule (const Matrix& m, const Matrix& b);

#endif // LinearAlgebra_h
