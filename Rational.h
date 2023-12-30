#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

int FindGCD(int m, int n);
int FindLCM(int m, int n);

class Rational
{
private:
    int numerator, denominator;
public:
    Rational();
    Rational(int n);
    Rational(int n, int d);
    Rational(const Rational& other);
    bool IsInt()const;
    int GetNumer()const;
    int GetDenom()const;
    void SetNumer(int n);
    void SetDenom(int d);
    Rational Simplify()const;
    Rational Inverse() const;
    double ToDouble() const;
    Rational operator+ (const Rational& b)const;
    Rational operator- (const Rational& b)const;
    Rational operator* (const Rational& b)const;
    Rational operator/ (const Rational& b)const;
    bool operator==(const Rational& b)const;
    bool operator!=(const Rational& b)const;
};
std::ostream& operator<<(std::ostream& os, const Rational& b);
Rational pow (const Rational& a, int e);

#endif // RATIONAL_H
