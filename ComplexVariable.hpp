#pragma once

#include <complex>
#include <iostream>

namespace solver
{

static const std::complex<double> ZERO = std::complex(0.0,0.0);

class ComplexVariable
{
private:
    std::complex<double> _a, _b, _c;
    int _degree, _len;
    double _ans1, _ans2;
public:


public:
    ComplexVariable() : _a(0), _b(1), _c(0), _degree(1), _len(1){};
    ComplexVariable(const double &c) : _a(0), _b(0), _c(c), _degree(0), _len(1){};
    ComplexVariable(const std::complex<double> &c) : _a(0), _b(0), _c(c)
    {
        _len = 0;
        if (_c != ZERO)
        {
            _degree = 0;
            ++_len;
        }
        if (_b != ZERO)
        {
            _degree = 1;
            ++_len;
        }
        if (_a != ZERO)
        {
            _degree = 2;
            ++_len;
        }
    };
    ComplexVariable(const std::complex<double> &a,
                    const std::complex<double> &b,
                    const std::complex<double> &c): _a(a), _b(b), _c(c)

    {
        _len = 0;
        if (_c != ZERO)
        {
            _degree = 0;
            ++_len;
        }
        if (_b != ZERO)
        {
            _degree = 1;
            ++_len;
        }
        if (_a != ZERO)
        {
            _degree = 2;
            ++_len;
        }
    };
    ComplexVariable(const ComplexVariable &c) : _a(c._a), _b(c._b), _c(c._c)
    {
        _len = 0;
        if (_a != ZERO)
        {
            _degree = 2;
            ++_len;
        }
        if (_b != ZERO)
        {
            _degree = 1;
            ++_len;
        }
        if (_c != ZERO)
        {
            _degree = 0;
            ++_len;
        }
    }

    ~ComplexVariable() {}

    friend std::complex<double> solve(const ComplexVariable &c);

    friend ComplexVariable operator==(const ComplexVariable &ls, const ComplexVariable &rs);
    friend ComplexVariable operator^(const ComplexVariable &ls, const ComplexVariable &rs);
    friend ComplexVariable operator*(const ComplexVariable &ls, const ComplexVariable &rs);
    friend ComplexVariable operator-(const ComplexVariable &ls, const ComplexVariable &rs);
    friend ComplexVariable operator/(const ComplexVariable &ls, const ComplexVariable &rs);
    friend ComplexVariable operator+(const ComplexVariable &ls, const ComplexVariable &rs);
    friend std::ostream &operator<<(std::ostream &os, const ComplexVariable &r);
};
} // namespace solver   