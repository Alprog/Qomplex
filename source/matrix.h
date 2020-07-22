
#pragma once

#include "Complex.h";
#include <type_traits>
#include <concepts>
#include <vector>
#include <cmath>

#include <stdio.h>
#include <stdarg.h>
#include <array>

template <size_t Size>
struct bra;
template <size_t Size>
struct ket;

template<typename T>
concept ToMatrix = requires (T a) { a.ToMatrix(); };

template<typename T1, typename T2>
concept MultipliableMatrices = requires (T1 lhs, T2 rhs) { lhs.ToMatrix() * rhs.ToMatrix(); };

template<size_t R, size_t C>
concept ValidSize = (R >= 1 && C >= 1);

template <size_t R, size_t C> requires ValidSize<R, C>
struct Matrix
{
    static constexpr size_t Count = R * C;

    Complex m[R][C];

    Matrix()
    {
    }

    template <typename... Types>
    Matrix(Types... list) requires CtorValid<Count, Types...>
    {
        Complex args[Count] { list... };
        auto ptr = m[0];
        for (auto complex : args)
        {
            *ptr++ = complex;
        }
    }

    Matrix(bra<C> bra) requires (R == 1)
    {
        for (size_t c = 0; c < R; c++)
        {
            m[0][c] = bra.component[c];
        }
    }

    Matrix(ket<R> ket) requires (C == 1)
    {
        for (size_t r = 0; r < R; r++)
        {
            m[r][0] = ket.component[r];
        }
    }

    Matrix<C, R> transpose()
    {
        Matrix<C, R> result;
        for (size_t r = 0; r < R; r++)
        {
            for (size_t c = 0; c < C; c++)
            {
                result.m[c][r] = m[r][c];
            }
        }
        return result;
    }

    Matrix<C, R> hermitian_conjugate()
    {
        Matrix<C, R> result;
        for (size_t r = 0; r < R; r++)
        {
            for (size_t c = 0; c < C; c++)
            {
                result.m[c][r] = m[r][c].conjugate();
            }
        }
        return result;
    }

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

    constexpr size_t size() { return Size; };
};

template <size_t Size>
struct bra : complex_vector<Size>
{
    auto ToMatrix() { return Matrix<1, Size>(*this); }
};

template <size_t Size>
struct ket : complex_vector<Size>
{
    auto ToMatrix() { return Matrix<Size, 1>(*this); }
};

template<size_t R1, size_t C1, size_t R2, size_t C2>
auto operator*(Matrix<R1, C1> lhs, Matrix<R2, C2> rhs) requires (C1 == R2)
{
    auto size = C1;

    Matrix<R1, C2> result;
    for (size_t r = 0; r < R1; r++)
    {
        for (size_t c = 0; c < C2; c++)
        {
            Complex value{ 0, 0 };
            for (size_t i = 0; i < size; i++)
            {
                value = value + lhs.m[r][i] * rhs.m[i][c];
            }
            result.m[r][c] = value;
        }
    }

    return result.simplify();
}

template<typename T1, typename T2>
auto operator*(T1 lhs, T2 rhs) requires MultipliableMatrices<T1, T2>
{
    return lhs.ToMatrix() * rhs.ToMatrix();
}