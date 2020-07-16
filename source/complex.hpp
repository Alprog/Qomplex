
#pragma once

#include "scalar.hpp"

struct Complex
{
    Scalar real;
    Scalar imaginary;

    Complex(Scalar real, Scalar imaginary)
        : real{real}
        , imaginary{imaginary}
    {
    }
};
