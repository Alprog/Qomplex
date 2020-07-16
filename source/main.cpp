
#include <iostream>

#include "scalar.hpp"
#include "complex.hpp"

int main()
{
    Scalar scalar{ 3.0f };
    
    Complex complex = Complex{ 1.0f, 2.0f };

    std::cout << complex.real.value;

    return 0;
}