
#pragma once

#include "complex.h"
#include <array>

template<int Size, typename... Types>
concept CtorValid = requires (Types... list) { std::array<Complex, Size>{ (Complex)list... }; } &&
                             (sizeof...(Types) == Size);

template <int Size>
struct complex_array
{
    Complex data[Size];

    complex_array(Complex args[Size])
        : data{args}
    {
    }

    template<typename... Types>
    complex_array(Types... args) requires CtorValid<Size, Types...>
        : data{(Complex)args...}
    {
    }

    constexpr size_t size() { return Size; };
};

#define TemplateCtor(class, base) \
template<typename... Types> \
class(Types... args) requires CtorValid<Size, Types...> \
: base<Size>{ args... } \
{}