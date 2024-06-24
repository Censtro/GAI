#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double real, double imagenary) : real(real), imagenary(imagenary) {}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
    return ComplexNumber(real + other.real, imagenary + other.imagenary);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const {
    return ComplexNumber(-real + other.real, -imagenary + other.imagenary);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const {
    double realpart = real * other.real - imagenary * other.imagenary;
    double imagepart = real * other.imagenary + imagenary * other.real;
    return ComplexNumber(realpart, imagepart);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const {
    double denominator = (other.real * other.real) + (other.imagenary * other.imagenary);
    double realpart = (real * other.real + imagenary * other.imagenary) / denominator;
    double imagepart = (imagenary * other.real - real * other.imagenary) / denominator;
    return ComplexNumber(realpart, imagepart);
}

std::ostream& operator<<(std::ostream& os, const ComplexNumber& complex) {
    if (complex.imagenary == 0) {
        os << complex.real;
    } else {
        if (complex.imagenary >= 0)
            os << complex.real << " + " << complex.imagenary << "i";
        else
            os << complex.real << " - " << -complex.imagenary << "i";
    }
    return os;
}

std::istream& operator>>(std::istream& in, ComplexNumber& complex) {
    in >> complex.real;
    if (in.peek() == ' ' || in.peek() == '\n') {
        complex.imagenary = 0;
    } else {
        char plus_minus;
        in >> plus_minus;
        if (plus_minus == '+' || plus_minus == '-') {
            in >> complex.imagenary;
            if (plus_minus == '-')
                complex.imagenary *= -1;
            in.ignore(std::numeric_limits<std::streamsize>::max(), 'i');
        } else {
            in.unget();
            complex.imagenary = 0;
        }
    }
    return in;
}

ComplexNumber sqrt(const ComplexNumber& num) {
    double realPart = std::sqrt((num.real + std::sqrt(num.real * num.real + num.imagenary * num.imagenary)) / 2);
    double imaginaryPart = num.imagenary >= 0 ? 1 : -1;
    imaginaryPart *= std::sqrt((-num.real + std::sqrt(num.real * num.real + num.imagenary * num.imagenary)) / 2);
    return ComplexNumber(realPart, imaginaryPart);
}

std::pair<ComplexNumber, ComplexNumber> solveQuadratic(ComplexNumber& a, ComplexNumber& b, ComplexNumber& c) {
    ComplexNumber discriminant = b * b - ComplexNumber(4) * a * c;
    ComplexNumber root1 = (ComplexNumber(-1) * b + sqrt(discriminant)) / (ComplexNumber(2) * a);
    ComplexNumber root2 = (ComplexNumber(-1) * b - sqrt(discriminant)) / (ComplexNumber(2) * a);
    return std::make_pair(root1, root2);
}
