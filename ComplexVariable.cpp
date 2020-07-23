#include "ComplexVariable.hpp"

solver::ComplexVariable solver::operator==(const solver::ComplexVariable &ls, const solver::ComplexVariable &rs)
{
    return ls - rs;
}
solver::ComplexVariable solver::operator^(const solver::ComplexVariable &ls, const solver::ComplexVariable &rs)
{
    if (ls._degree != 1 || ls._len != 1 || rs._degree != 0 || rs._len != 1 || rs._c != std::complex(2.0,0.0))
    {
        throw std::runtime_error("ERR: Function support only (by)^2 form");
    }
    std::complex<double> a, b, c;
    a = std::pow(ls._b, rs._c);
    b = 0;
    c = 0;
    return ComplexVariable(a, b, c);
}
solver::ComplexVariable solver::operator*(const solver::ComplexVariable &ls, const solver::ComplexVariable &rs)
{
    if (ls._degree + rs._degree > 2)
        throw std::runtime_error("ERR: Can't solve a function higher then a quadric function");

    std::complex<double> a, b, c;
    a = ls._a * rs._c + ls._b * rs._b + ls._c * rs._a;
    b = ls._b * rs._c + ls._c * rs._b;
    c = ls._c * rs._c;
    return ComplexVariable(a, b, c);
}
solver::ComplexVariable solver::operator-(const solver::ComplexVariable &ls, const solver::ComplexVariable &rs)
{
    std::complex<double> a, b, c;
    a = ls._a - rs._a;
    b = ls._b - rs._b;
    c = ls._c - rs._c;
    return ComplexVariable(a, b, c);
}
solver::ComplexVariable solver::operator+(const solver::ComplexVariable &ls, const solver::ComplexVariable &rs)
{
    std::complex<double> a, b, c;
    a = ls._a + rs._a;
    b = ls._b + rs._b;
    c = ls._c + rs._c;
    return ComplexVariable(a, b, c);
}
solver::ComplexVariable solver::operator/(const solver::ComplexVariable &ls, const solver::ComplexVariable &rs)
{
    if (rs._degree != 0)
    {
        throw std::runtime_error("ERR: Function can divide only by a simple double");
    }

    if (rs._c == solver::ZERO)
    {
        throw std::runtime_error("ERR: Can't divide by zero");
    }
    std::complex<double> a, b, c;
    a = ls._a / rs._c;
    b = ls._b / rs._c;
    c = ls._c / rs._c;
    return ComplexVariable(a, b, c);
}
std::ostream &solver::operator<<(std::ostream &os, const solver::ComplexVariable &r)
{
    return (os << r._a << "(y)^2 + " << r._b << "y + " << r._c);
}
