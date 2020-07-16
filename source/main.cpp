
#include <iostream>

#include "real.h"
#include "complex.h"
#include "ket_vector2.h"
#include "matrix2x2.h"

int main()
{
    Real scalar{ 3.0f };
    
    Complex complex = Complex{ 3.0f, 2.0f };

    std::cout << complex.modulus().value;


    return 0;
}