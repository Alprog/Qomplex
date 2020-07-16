
#include <iostream>
#include "ket_vector2.h"

bra_vector2 ket_vector2::hermitian_conjugate()
{
    return bra_vector2{ v1.conjugate(), v2.conjugate() };
}

Real ket_vector2::norm()
{
    auto complex = this->hermitian_conjugate() * (*this);

    if (complex.imaginary.value != 0)
    {
        throw std::exception("scalar product with itself is not real!");
    }

    return complex.real;
}

ket_vector2 ket_vector2::normalize()
{
    auto norm = this->norm();
    return ket_vector2
    {
        v1 / norm,
        v2 / norm
    };
}