
#pragma once

#include "real.h"

struct Complex
{
    Real real;
    Real imaginary;

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

    friend Complex operator*(Complex lhs, Complex rhs)
    {
        // (a + bi)(c + di) = ac + bci + adi + bd(i^2) = (ac - bd) + (bc + ad)*i 
        return Complex(
            lhs.real * rhs.real - lhs.imaginary * rhs.imaginary,
            lhs.real * rhs.imaginary + lhs.imaginary * rhs.real
        );
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
