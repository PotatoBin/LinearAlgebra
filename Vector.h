#ifndef Vector_h
#define Vector_h
#include "Rational.h"

class Vector {
private:
    int Size;
    std::vector<Rational> vector;

public :
    Vector(std::initializer_list<Rational> elements);
    Vector(int num);
    void SetElement(int num, Rational e);
    int GetSize() const;
    Rational GetElement(int num) const;
    Vector operator+ (const Vector& b) const;
    Vector operator- (const Vector& b) const;
    Vector operator* (const Rational& b) const;
    bool operator==(const Vector& b) const;
    bool operator!=(const Vector& b) const;
};

std::ostream& operator<<(std::ostream& os, const Vector& b);

#endif /* Vector_h */
