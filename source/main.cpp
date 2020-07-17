
#include <iostream>

#include "real.h"
#include "complex.h"
#include "bra_vector2.h"
#include "ket_vector2.h"
#include "matrix2x2.h"
#include "matrix.h"

int main()
{
    Real scalar{ 3.0f };

    Complex complex = Complex{ 3.0f, 2.0f };

    bra_vector2 bra
    {
        Complex(1, 2),
        Complex(3, 4)
    };

    ket_vector2 ket
    {
        Complex(5, 6),
        Complex(7, 8)
    };

    auto c = bra * bra.hermitian_conjugate();

    std::cout << c.real.value << " " << c.imaginary.value << "\n";

    Matrix<1, 4> matrix;

    matrix.b();

    Matrix<4, 4> matrix;

    matrix.b();

    //matrix.m[3][3] = Complex(3, 3);

    return 0;
}