
#pragma once

#include "complex.h"
#include "ket_vector2.h"

struct ket_vector2;

struct bra_vector2
{
    Complex v1, v2;

    bra_vector2(Complex v1, Complex v2)
        : v1{ v1 }
        , v2{ v2 }
    {
    }

    ket_vector2 hermitian_conjugate();

    friend Complex operator*(bra_vector2 bra, ket_vector2 ket);
};