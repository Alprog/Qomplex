
#pragma once

#include "Complex.h";
#include <type_traits>
#include <concepts>
#include <vector>
#include <cmath>

template <size_t Size>
struct bra;
template <size_t Size>
struct ket;

template<int T>
concept Concept = T == 1;

template<typename T>
concept ToMatrix = requires (T a) { a.ToMatrix(); };

template<typename T1, typename T2>
concept MultipliableMatrices = requires (T1 lhs, T2 rhs) { lhs.ToMatrix() * rhs.ToMatrix(); };

template<size_t R, size_t C>
concept ValidSize = (R >= 1 && C >= 1);

template <size_t R, size_t C> requires ValidSize<R, C>
struct Matrix
{
    Complex m[R][C];

    void a() {}

    void b() requires Concept<R> {}

    Matrix()
    {
    }

    Matrix(bra<C>);
    Matrix(ket<R>);

    /*template<int R2, int C2>
    friend Matrix<R, C2> operator*(Matrix lhs, Matrix<R2, C2> rhs)
    {
        return Matrix<R, C2>{};
    }*/

    Matrix ToMatrix() { return *this; }

    Complex simplify() requires (R == 1 && C == 1) { return m[0][0]; };
    bra<C> simplify() requires (R == 1 && C != 1) { return bra<C>{}; };
    ket<R> simplify() requires (R != 1 && C == 1) { return ket<R>{}; };
    Matrix simplify() requires (R != 1 && C != 1) { return *this; }
};

template <size_t Size>
struct complex_vector
{
    Complex component[Size];

    size_t size() { return Size; };
};

template <size_t Size>
struct bra : complex_vector<Size>
{
    Matrix<1, Size> ToMatrix()
    {
        return Matrix<1, Size>();
    }
};

template <size_t Size>
struct ket : complex_vector<Size>
{
    Matrix<Size, 1> ToMatrix()
    {
        return Matrix<Size, 1>();
    }
};

/*template<int R1, int C1, int R2, int C2>
Complex operator*(Matrix<R1, C1> lhs, Matrix<R2, C2> rhs) requires (C1 == R2) && (C2 == 1 && R1 == 1)
{
    return Complex{ 0, 0 };
}*/

template <size_t R, size_t C> requires ValidSize<R, C>
Matrix<R, C>::Matrix(bra<C>)
{

}

template <size_t R, size_t C> requires ValidSize<R, C>
Matrix<R, C>::Matrix(ket<R>)
{

}

template<size_t R1, size_t C1, size_t R2, size_t C2>
auto operator*(Matrix<R1, C1> lhs, Matrix<R2, C2> rhs) requires (C1 == R2)
{
    Matrix<R1, C2> result;

    for (size_t r = 0; r <= R1; r++)
    {
        for (size_t c = 0; c < C2; c++)
        {
        }
    }

    return result.simplify();
}

template<typename T1, typename T2>
auto operator*(T1 lhs, T2 rhs) requires MultipliableMatrices<T1, T2>
{
    return lhs.ToMatrix() * rhs.ToMatrix();
}