#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>
#include <cmath>
#include <limits>

class ComplexNumber {
public:
    double real;
    double imagenary;

    ComplexNumber(double real = 0, double imagenary = 0);

    ComplexNumber operator+(const ComplexNumber& other) const;
    ComplexNumber operator-(const ComplexNumber& other) const;
    ComplexNumber operator*(const ComplexNumber& other) const;
    ComplexNumber operator/(const ComplexNumber& other) const;

    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& complex);
    friend std::istream& operator>>(std::istream& in, ComplexNumber& complex);
};

ComplexNumber sqrt(const ComplexNumber& num);
std::pair<ComplexNumber, ComplexNumber> solveQuadratic(ComplexNumber& a, ComplexNumber& b, ComplexNumber& c);

#endif // COMPLEXNUMBER_H

