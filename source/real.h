
#pragma once

#include <math.h>

struct Real
{
    float value;

    Real(float value)
        : value{value}
    {
    }

    Real pow2()
    {
        return value * value;
    }

    Real sqrt()
    {
        return sqrtf(value);
    }

    friend Real operator-(Real scalar)
    {
        return -scalar.value;
    }

    friend Real operator+(Real lhs, Real rhs)
    {
        return Real(lhs.value + rhs.value);
    }

    friend Real operator-(Real lhs, Real rhs)
    {
        return Real(lhs.value - rhs.value);
    }

    friend Real operator*(Real lhs, Real rhs)
    {
        return Real(lhs.value * rhs.value);
    }

    friend Real operator/(Real lhs, Real rhs)
    {
        return Real(lhs.value / rhs.value);
    }
};