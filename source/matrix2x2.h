
#pragma once

#include "complex.h"

struct Matrix2x2
{
    Complex m11, m12;
    Complex m21, m22;

    Matrix2x2(Complex m11, Complex m12,
              Complex m21, Complex m22)
        : m11{m11}
        , m12{m12}
        , m21{m21}
        , m22{m22}
    {
    }

    Matrix2x2 transpose()
    {
        return
        {
            m11, m21,
            m12, m22
        };
    }

    Matrix2x2 hermitian_conjugate()
    {
        return
        {
            m11.conjugate(), m21.conjugate(),
            m12.conjugate(), m22.conjugate()
        };
    }
};