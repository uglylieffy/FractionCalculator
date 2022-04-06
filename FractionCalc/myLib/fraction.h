#ifndef FRACTION_H
#define FRACTION_H

#include "Fraction_global.h"
#pragma once

#include <iostream>
using namespace std;

class FractionException {
public:
    FractionException(const string&);
    string& what();
private:
    string message;
};

class FRACTION_EXPORT Fraction
{
public:
    Fraction();
    Fraction(int t);
    Fraction(int t, int b);
    int getNumber();

    // Returns the numerator.
    int numerator() const;

    // Returns the denominator.
    int denominator() const;

    // Updates a fraction by adding in another fraction value.
    Fraction& operator+=(const Fraction& right);

    // Increment fraction by 1.
    Fraction& operator++(); 			// Preincrement form
    Fraction operator++(int unused); // Postincrement form

    // Compare one fraction value to another.
    // Result is negative if less than right, zero if equal, and
    // positive if greater than right.
    int compare(const Fraction& right) const;

private:
   // Place the fraction in lowest common denominator form.
   void normalize();

   // Compute the greatest common denominator of two integer values.
   int gcd(int n, int m);

   int top;			// numerator
   int bottom;		// denominator
};
// Non-member overloaded arithmetic operators
Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);
Fraction operator*(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& value);

// Non-member overloaded boolean operators
bool operator<(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);
bool operator==(const Fraction& left, const Fraction& right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator>=(const Fraction& left, const Fraction& right);
bool operator>(const Fraction& left, const Fraction& right);

// Non-member stream operators
ostream& operator<<(ostream& out, const Fraction& value);
istream& operator>>(istream& in, Fraction& retFrac);

#endif // FRACTION_H
