
#include "complex.h"

Complex operator "" _i(long double imaginary)
{
    return Complex(0, imaginary);
}