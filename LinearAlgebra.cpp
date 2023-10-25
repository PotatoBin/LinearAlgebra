#include "LinearAlgebra.h"

Matrix pow (const Matrix& m, int e){
    if (m.GetColSize() != m.GetRowSize()){
        throw std::runtime_error("ERROR: THE MATRIX MUST BE A 2X2 MATRIX SQUARE MATRIX");
    }
    Matrix result(m);
    for(int i =0;i<e;++i){
        result = result * m;
    }
    return result;
}

Matrix inverse2x2 (const Matrix& m){
    if(m.GetRowSize() != 2 || m.GetColSize() != 2){
        throw std::runtime_error("ERROR: THE MATRIX MUST BE A 2X2 MATRIX");
    }
    Rational detVal(det(m));
    if(detVal == Rational()){
        throw std::runtime_error("ERROR: NON-INVERTIBLE MATRIX");
    }
    Matrix result (2, 2);
    result.SetElement(1, 1, m.GetElement(2, 2));
    result.SetElement(2, 2, m.GetElement(1, 1));
    result.SetElement(1, 2, m.GetElement(1, 2) * -1);
    result.SetElement(2, 1, m.GetElement(2, 1) * -1);
    return result*(detVal.Inverse());
}

Matrix inverse (const Matrix& m){
    return adj(m) * det(m).Inverse();
}

Matrix diag(const std::initializer_list<Rational> elements){
    Matrix diag(static_cast<int>(elements.size()));
    const Rational* iter = elements.begin();
    for(int i=1;i<=elements.size();++i){
        diag.SetElement(i, i, *iter);
        ++iter;
    }
    return diag;
}

Matrix diag(const std::initializer_list<int> elements){
    Matrix diag(static_cast<int>(elements.size()));
    const int* iter = elements.begin();
    for(int i=1;i<=elements.size();++i){
        diag.SetElement(i, i, Rational(*iter));
        ++iter;
    }
    return diag;
}

Rational tr(const Matrix& m){
    if (not m.IsSquare()){
        throw std::runtime_error("ERROR: THE MATRIX MUST BE A SQUARE MATRIX");
    }
    Rational sum;
    for(int i=1;i<=m.GetRowSize();++i){
        sum = sum + m.GetElement(i, i);
    }
    return sum;
}

Rational srrusRule(const Matrix& m) {
    if (m.GetRowSize() != 3 || m.GetColSize() != 3) {
        throw std::runtime_error("ERROR: THE MATRIX MUST BE A 3X3 MATRIX");
    }

    Rational det;

    det = m.GetElement(1, 1) * m.GetElement(2, 2) * m.GetElement(3, 3)
        + m.GetElement(1, 2) * m.GetElement(2, 3) * m.GetElement(3, 1)
        + m.GetElement(1, 3) * m.GetElement(2, 1) * m.GetElement(3, 2)
        - m.GetElement(1, 3) * m.GetElement(2, 2) * m.GetElement(3, 1)
        - m.GetElement(1, 2) * m.GetElement(2, 1) * m.GetElement(3, 3)
        - m.GetElement(1, 1) * m.GetElement(2, 3) * m.GetElement(3, 2);

    return det;
}

Rational det(const Matrix& m){
    if (not m.IsSquare()){
        throw std::runtime_error("ERROR: THE MATRIX MUST BE A SQUARE MATRIX");
    }
    Rational result;
    if(m.GetColSize() == 2){
        result = (m.GetElement(1, 1) * m.GetElement(2, 2)) - (m.GetElement(1, 2) * m.GetElement(2, 1));
        return result;
    }
    for(int i=1;i<=m.GetRowSize();++i){
        result = result + (m.GetElement(1, i) * cofactor(m, 1, i));
    }
    return result;
}



Rational cofactor(const Matrix& m, int a, int b) {
    if (not m.IsSquare()){
        throw std::runtime_error("ERROR: THE MATRIX MUST BE A SQUARE MATRIX");
    }
    Rational c = pow(Rational(-1), a+b);
    Matrix d(m.GetRowSize()-1, m.GetColSize()-1);
    int di = 1;
    for (int i = 1; i <=m.GetRowSize(); ++i) {
        if (i == a) {continue;}
        int dj = 1;
        for (int j = 1; j <= m.GetColSize(); ++j) {
            if (j == b) {continue;}
            d.SetElement(di, dj, m.GetElement(i, j));
            ++dj;
        }
        ++di;
    }
    return det(d) * c;
}

Matrix adj(const Matrix& m){
    Matrix result(m);
    for(int i=1;i<=m.GetRowSize();++i){
        for(int j=1;j<=m.GetColSize();++j){
            result.SetElement(i, j, cofactor(m, i, j));
        }
    }
    return result.Transpose();
}

Matrix cramerRule (const Matrix& m, const Matrix& b){
    if(b.GetColSize()!=1) {
        throw std::runtime_error("ERROR: THE SECOND MATRIX MUST BE A COLUMN VECTOR");
    }
    Matrix x(m.GetColSize(),1);
    Rational detVal = det(m);
    for(int i =1;i<=b.GetRowSize();++i){
        x.SetElement(i, 1, det(m.SetColVector(i, b)) / detVal);
    }
    return x;
}
