
#pragma once

#include "Complex.h";
#include <type_traits>
#include <concepts>
#include <vector>
#include <cmath>

template<int T>
concept Concept = T == 1;


template <int A, int B>
struct Matrix
{
    Complex m[A][B];

    void a() {}

    void b() requires Concept<A> {}
};