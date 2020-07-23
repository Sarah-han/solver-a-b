#include "RealVariable.hpp"
#include <math.h>

solver::RealVariable solver::operator==(const solver::RealVariable &ls, const solver::RealVariable &rs)
{
   return ls - rs;
}
// support only form (x)^2
solver::RealVariable solver::operator^(const solver::RealVariable &ls, const solver::RealVariable &rs)
{
   if (ls._degree != 1 || ls._len != 1 || rs._degree != 0 || rs._len != 1 || rs._c != 2)
   {
      throw std::runtime_error("ERR: Function support only (bx)^2 form");
   }
   double a, b, c;
   a = std::pow(ls._b, rs._c);
   b = 0;
   c = 0;
   return RealVariable(a, b, c);
}
// Done
solver::RealVariable solver::operator*(const solver::RealVariable &ls, const solver::RealVariable &rs)
{
   if (ls._degree + rs._degree > 2)
      throw std::runtime_error("ERR: Can't solve a function higher then a quadric function");

   double a, b, c;
   a = ls._a * rs._c + ls._b * rs._b + ls._c * rs._a;
   b = ls._b * rs._c + ls._c * rs._b;
   c = ls._c * rs._c;
   return RealVariable(a, b, c);
}
// Done
solver::RealVariable solver::operator-(const solver::RealVariable &ls, const solver::RealVariable &rs)
{
   double a, b, c;
   a = ls._a - rs._a;
   b = ls._b - rs._b;
   c = ls._c - rs._c;
   return RealVariable(a, b, c);
}
// Done 
solver::RealVariable solver::operator+(const solver::RealVariable &ls, const solver::RealVariable &rs)
{
   double a, b, c;
   a = ls._a + rs._a;
   b = ls._b + rs._b;
   c = ls._c + rs._c;
   return RealVariable(a, b, c);
}
// support only devision by double
solver::RealVariable solver::operator/(const solver::RealVariable &ls, const solver::RealVariable &rs)
{
   if (rs._degree != 0)
   {
      throw std::runtime_error("ERR: Function can divide only by a simple double");
   }
   
   double a, b, c;
   a = ls._a / rs._c;
   b = ls._b / rs._c;
   c = ls._c / rs._c;
   return RealVariable(a, b, c);
}
// Done
std::ostream &solver::operator<<(std::ostream &os, const solver::RealVariable &r)
{
   return (os << r._a << "(x)^2 + " << r._b << "x + " << r._c);
}
