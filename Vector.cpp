#include "Vector.h"

Vector::Vector(std::initializer_list<Rational> elements) : vector(elements) { Size = static_cast<int>(vector.size()); }

Vector::Vector(int num) : Size(num), vector(num, 0) { }

void Vector::SetElement(int num, Rational e) {
    if (num < 1 || num > Size) {
        throw std::out_of_range("ERROR: INDEX OUT OF RANGE");
    }
    vector[num-1] = e;
}

int Vector::GetSize() const {
    return Size;
}

Rational Vector::GetElement(int num) const {
    return vector[num - 1];
}

Vector Vector::operator+ (const Vector& b) const {
    if (Size != b.GetSize()) {
        throw std::runtime_error("ERROR: VECTOR OF DIFFERENT SIZE");
    }
    Vector result(Size);
    for (int i = 1; i <= Size; ++i) {
        result.SetElement(i, GetElement(i) + b.GetElement(i));
    }
    return result;
}

Vector Vector::operator- (const Vector& b) const {
    if (Size != b.GetSize()) {
        throw std::runtime_error("ERROR: VECTOR OF DIFFERENT SIZE");
    }
    Vector result(Size);
    for (int i = 1; i <= Size; ++i) {
        result.SetElement(i, GetElement(i) - b.GetElement(i));
    }
    return result;
}

Vector Vector::operator* (const Rational& b) const {
    Vector result(GetSize());
    for (int i = 1; i <= GetSize(); ++i) {
        result.SetElement(i, GetElement(i) * b);
    }
    return result;
}

bool Vector::operator==(const Vector& b) const {
    if (GetSize() != b.GetSize()) {
        return false;
    }
    for (int i = 1; i <= GetSize(); ++i) {
        if (GetElement(i) != b.GetElement(i)) {
            return false;
        }
    }
    return true;
}

bool Vector::operator!=(const Vector& b) const {
    return !(*this == b);
}

std::ostream& operator<<(std::ostream& os, const Vector& b){
    os << "[ ";
    for (int i = 1; i <= b.GetSize(); ++i) {
        os << b.GetElement(i) << " ";
    }
    os << "]";
    return os;
}
