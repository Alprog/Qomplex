
#pragma once

#include "real.h"
#include "common.h"

struct Complex
{
    Real real;
    Real imaginary;

    Complex()
        : real {0}
        , imaginary {0}
    {
    }

    Complex(float real)
        : real{ real }
        , imaginary{ 0 }
    {
    }

    Complex(Real real)
        : real{ real }
        , imaginary{ 0 }
    {
    }

    Complex(Real real, Real imaginary)
        : real{real}
        , imaginary{imaginary}
    {
    }

    friend Complex operator+(Complex lhs, Complex rhs)
    {
        return Complex(
            lhs.real + rhs.real, 
            lhs.imaginary + rhs.imaginary
        );
    }

    friend Complex operator-(Complex lhs, Complex rhs)
    {
        return Complex(
            lhs.real - rhs.real,
            lhs.imaginary - rhs.imaginary
        );
    }

    friend Complex operator-(Complex complex)
    {
        return Complex(
            -complex.real,
            -complex.imaginary
        );
    }

    friend Complex operator*(Complex lhs, Complex rhs)
    {
        // (a + bi)(c + di) = ac + bci + adi + bd(i^2) = (ac - bd) + (bc + ad)*i 
        return Complex(
            lhs.real * rhs.real - lhs.imaginary * rhs.imaginary,
            lhs.real * rhs.imaginary + lhs.imaginary * rhs.real
        );
    }

    friend Complex operator/(Complex complex, Real value)
    {
        return Complex{ complex.real / value, complex.imaginary / value };
    }

    friend bool operator==(Complex lhs, Complex rhs)
    {
        return lhs.real == rhs.real && lhs.imaginary == rhs.imaginary;
    }

    friend bool operator!=(Complex lhs, Complex rhs)
    {
        return lhs.real != rhs.real || lhs.imaginary != rhs.imaginary;
    }

    Real modulus()
    {
        return sqrt(real.pow2() + imaginary.pow2());
    }

    Complex conjugate()
    {
        return Complex{ real, -imaginary };
    }
};

Complex operator "" _i(long double imaginary);