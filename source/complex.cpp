
#include "complex.h"

Complex operator "" _i(unsigned long long imaginary)
{
    return Complex(0, imaginary);
}

Complex operator "" _i(long double imaginary)
{
    return Complex(0, imaginary);
}