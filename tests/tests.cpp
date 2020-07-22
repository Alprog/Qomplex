
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

    assert(result[0][0] == 1 - 2_i); assert(result[0][1] == -2 + 4_i);
    assert(result[1][0] == 3 + 5_i); assert(result[1][1] == 2_i);
}

void test_hermitian_conjugate()
{
    Matrix<2, 2> matrix
    {
        1 - 2_i, -2 + 4_i,
        3 + 5_i,   2_i
    };

    auto result = matrix.hermitian_conjugate();

    assert(result[0][0] ==  1 + 2_i); assert(result[0][1] == 3 - 5_i);
    assert(result[1][0] == -2 - 4_i); assert(result[1][1] == -2_i);
}

void test_dot_product()
{
    bra<2> bra{ 3, 2 };
    ket<2> ket
    {
        3, 
        0 
    };
    
    auto result = bra * ket;

    assert(result == 9);
}

void test_matrix_ket()
{
    Matrix<2, 2> matrix
    {
        2, 1,
        1, 2
    };

    ket<2> ket
    {
        1,
        1
    };

    auto result = matrix * ket;

    //assert(result[0] == 3 && result[1] == 3);
}

void run_tests()
{
    test_matrices_multiplication();
    test_hermitian_conjugate();
    test_dot_product();
    test_matrix_ket();
}