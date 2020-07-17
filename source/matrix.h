
#pragma once

#include "Complex.h";
#include <type_traits>
#include <concepts>
#include <vector>
#include <cmath>

template<int T>
concept Concept = T == 1;

template <size_t Size>
struct bra
{
    Complex component[Size];

    size_t size() { return Size; };
};

template <int R, int C> requires (R >= 1 && C >= 1)
struct Matrix
{
    Complex m[R][C];

    void a() {}

    void b() requires Concept<R> {}

    Matrix()
    {
    }

    Matrix(bra<C> bra)
    {
    }
};

template<int R1, int C1, int R2, int C2>
Complex operator*(Matrix<R1, C1> lhs, Matrix<R2, C2> rhs) requires (C1 == R2) && (C2 == 1 && R1 == 1)
{
    return Complex{ 0, 0 };
}

template<int R1, int C1, int R2, int C2>
Matrix<R1, C2> operator*(Matrix<R1, C1> lhs, Matrix<R2, C2> rhs) requires (C1 == R2) && (C2 != 1 || R1 != 1)
{
    for (size_t r = 0; r <= R1; r++)
    {
        for (size_t c = 0; c < C2; c++)
        {
        }
    }

    return Matrix<R1, C2>{};
}