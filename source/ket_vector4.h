
#pragma once

#include "complex.h"

struct ket_vector4
{
    Complex v1;
    Complex v2;
    Complex v3;
    Complex v4;

    ket_vector4(Complex v1, Complex v2, Complex v3, Complex v4)
        : v1{v1}
        , v2{v2}
        , v3{v3}
        , v4{v4}
    {
    }
};