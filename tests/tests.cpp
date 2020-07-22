
#include "tests.h"
#include <iostream>
#include "../source/matrix.h"
#include "../source/complex_array.h"

#define assert(expression) if (!(expression)) std::cout << #expression << std::endl;

void test_matrices_multiplication()
{
    Matrix<2, 2> lhs
    {
        1,       1 - 1_i,
        1 + 1_i,   -1
    };

    Matrix<2, 2> rhs
    {
        3,     2_i,
        -2_i,  -2
    };

    auto result = lhs * rhs;

    assert(result.m[0][0] == 1 - 2_i); assert(result.m[0][1] == -2 + 4_i);
    assert(result.m[1][0] == 3 + 5_i); assert(result.m[1][1] == 2_i);
}

void test_hermitian_conjugate()
{
    Matrix<2, 2> matrix;
    matrix.m[0][0] = 1 - 2_i; matrix.m[0][1] = -2 + 4_i;
    matrix.m[1][0] = 3 + 5_i; matrix.m[1][1] = 2_i;

    auto result = matrix.hermitian_conjugate();

    assert(result.m[0][0] ==  1 + 2_i); assert(result.m[0][1] == 3 - 5_i);
    assert(result.m[1][0] == -2 - 4_i); assert(result.m[1][1] == -2_i);
}

void test_dot_product()
{
    ket<2> ket;
    
    Matrix<2, 2> m{ 3, 3_i, 3_i, 3_i };

   // m.hermitian_conjugate();
}

void run_tests()
{
    test_matrices_multiplication();
    test_hermitian_conjugate();
    test_dot_product();

    complex_array<3> a{ 3, 3_i, 3_i };
}