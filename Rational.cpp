#include "Rational.h"

int FindGCD(int m, int n) {
    while (n) {
        int temp = n;
        n = m % n;
        m = temp;
    }
    return m;
}

int FindLCM(int m, int n) {
    int gcd = FindGCD(m, n);
    return (m / gcd) * n;
}

Rational pow (const Rational& a, int e){
    Rational result(1);
    for(int i =0;i<e;++i){
        result = result * a;
    }
    return result;
}

Rational::Rational() : numerator(0), denominator(1) {}

Rational::Rational(int n) : numerator(n), denominator(1) {}

Rational::Rational(int n, int d) : numerator(n) {
    if (d){
        denominator = d;
    }
    else {
        throw std::runtime_error("ERROR: ATTEMPTING TO DIVIDE BY ZERO");
    }
}

Rational::Rational(const Rational& other): numerator(other.GetNumer()), denominator(other.GetDenom()) {}

bool Rational::IsInt() const{
    return GetDenom() == 1;
}

int Rational::GetNumer()const{
    return numerator;
}

int Rational::GetDenom()const{
    return denominator;
}

void Rational::SetNumer(int n) {
    if (n == 0) {
        numerator = 0;
        denominator = 1;
    } else {
        numerator = n;
    }
}

void Rational::SetDenom(int d) {
    if (d == 0) {
        throw std::runtime_error("ERROR: ATTEMPTING TO DIVIDE BY ZERO");
    }
    if (d < 0) {
        numerator = -numerator;
        denominator = -d;
    } else {
        denominator = d;
    }
}

Rational Rational::Simplify() const {
    int gcd = FindGCD(GetNumer(), GetDenom());
    return Rational(GetNumer() / gcd, GetDenom() / gcd);
}

Rational Rational::Inverse() const {
    if (GetNumer() == 0) {
        throw std::invalid_argument("Cannot inverse a zero.");
    }
    return Rational(GetDenom(), GetNumer());
}

double Rational::ToDouble() const {
    return static_cast<double>(GetNumer()) / static_cast<double>(GetDenom());
}

Rational Rational::operator+(const Rational& b) const {
    int lcm = FindLCM(GetDenom(), b.GetDenom());
    Rational result(GetNumer() * (lcm / GetDenom()) + (b.GetNumer() * (lcm / b.GetDenom())) ,lcm);
    return result.Simplify();
}

Rational Rational::operator-(const Rational& b) const {
    int lcm = FindLCM(GetDenom(), b.GetDenom());
    Rational result(GetNumer() * (lcm / GetDenom()) - (b.GetNumer() * (lcm / b.GetDenom())), lcm);
    return result.Simplify();
}

Rational Rational::operator*(const Rational& b) const {
    Rational result(GetNumer() * b.GetNumer(), GetDenom() * b.GetDenom());
    return result.Simplify();
}

Rational Rational::operator/(const Rational& b) const {
    if (b.GetNumer() == 0) {
        throw std::runtime_error("ERROR: DIVISION BY ZERO");
    }
    Rational result(GetNumer() * b.GetDenom(), GetDenom() * b.GetNumer());
    return result.Simplify();
}

bool Rational::operator==(const Rational& b)const {
    return (GetNumer() == b.GetNumer()) && (GetDenom() == b.GetDenom());
}

bool Rational::operator!=(const Rational& b)const {
    return (GetNumer() != b.GetNumer()) || (GetDenom() != b.GetDenom());
}

std::ostream& operator<<(std::ostream& os, const Rational& b){
    os << b.GetNumer();
    if (b.IsInt()) {
        return  os;
    }
    else {
        os << "/";
        os << b.GetDenom();
        return  os;
    }
}
