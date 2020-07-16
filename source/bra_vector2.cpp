
#include <iostream>
#include "bra_vector2.h"

ket_vector2 bra_vector2::hermitian_conjugate()
{
    return ket_vector2
    {
        v1.conjugate(),
        v2.conjugate()
    };
}

Complex operator*(bra_vector2 bra, ket_vector2 ket)
{
    return bra.v1 * ket.v1 + bra.v2 + ket.v2;
}
