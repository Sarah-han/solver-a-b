#pragma once

#include <iostream>

namespace solver
{
class RealVariable
{
private:
    double _a, _b, _c;
    int _degree, _len;

public:
    RealVariable() : _a(0), _b(1), _c(0), _degree(1), _len(1){};
    RealVariable(const double &c) : _a(0), _b(0), _c(c), _degree(0), _len(1){};
    RealVariable(const double &a, const double &b, const double &c) : _a(a), _b(b), _c(c)
    {
         _len = 0;
        if (_c != 0)
        {
            _degree = 0;
            ++_len;
        }
        if (_b != 0)
        {
            _degree = 1;
            ++_len;
        }
        if (_a != 0)
        {
            _degree = 2;
            ++_len;
        }
    };
    RealVariable(const RealVariable &r) : _a(r._a), _b(r._b), _c(r._c)
    {
        _len = 0;
        if (_c != 0)
        {
            _degree = 0;
            ++_len;
        }
        if (_b != 0)
        {
            _degree = 1;
            ++_len;
        }
        if (_a != 0)
        {
            _degree = 2;
            ++_len;
        }
    };

    ~RealVariable() {}

    friend double solve(const RealVariable &r);

    friend RealVariable operator==(const RealVariable &ls, const RealVariable &rs);
    friend RealVariable operator^(const RealVariable &ls, const RealVariable &rs);
    friend RealVariable operator*(const RealVariable &ls, const RealVariable &rs);
    friend RealVariable operator-(const RealVariable &ls, const RealVariable &rs);
    friend RealVariable operator/(const RealVariable &ls, const RealVariable &rs);
    friend RealVariable operator+(const RealVariable &ls, const RealVariable &rs);
    friend std::ostream &operator<<(std::ostream &os, const RealVariable &r);
};
} // namespace solver
