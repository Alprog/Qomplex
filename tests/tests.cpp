
#include "tests.h"
#include <iostream>
#include "../source/matrix.h"

#define assert(expression) if (!(expression)) std::cout << #expression << std::endl;

void test_matrices_multiplication()
{
    Matrix<2, 2> lhs;
    lhs.m[0][0] = 1; lhs.m[0][1] = 1 - 1.0_i;
    lhs.m[1][0] = 1 + 1.0_i; lhs.m[1][1] = -1;

    Matrix<2, 2> rhs;
    rhs.m[0][0] = 3; rhs.m[0][1] = 2.0_i;
    rhs.m[1][0] = -2.0_i; rhs.m[1][1] = -2;

    auto result = lhs * rhs;

    assert(result.m[0][0] == 1 - 2.0_i); assert(result.m[0][1] == -2 + 4.0_i);
    assert(result.m[1][0] == 3 + 5.0_i); assert(result.m[1][1] == 2.0_i);
}

void test_hermitian_conjugate()
{
    Matrix<2, 2> matrix;
    matrix.m[0][0] = 1 - 2.0_i; matrix.m[0][1] = -2 + 4.0_i;
    matrix.m[1][0] = 3 + 5.0_i; matrix.m[1][1] = 2.0_i;

    auto result = matrix.hermitian_conjugate();

    assert(result.m[0][0] ==  1 + 2.0_i); assert(result.m[0][1] == 3 - 5.0_i);
    assert(result.m[1][0] == -2 - 4.0_i); assert(result.m[1][1] == -2.0_i);
}

void run_tests()
{
    test_matrices_multiplication();
    test_hermitian_conjugate();
}