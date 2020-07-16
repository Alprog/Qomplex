
#pragma once

#include "complex.h"
#include "bra_vector2.h"

struct bra_vector2;

struct ket_vector2
{
    Complex v1;
    Complex v2;

    ket_vector2(Complex v1, Complex v2)
        : v1{v1}
        , v2{v2}
    {
    }

    bra_vector2 hermitian_conjugate();

    Real norm();

    ket_vector2 normalize();
};