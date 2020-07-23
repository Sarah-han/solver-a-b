#pragma once

#include <iostream>
#include <complex>
#include "RealVariable.hpp"
#include "ComplexVariable.hpp"

namespace solver
{
double solve(const RealVariable &r);


std::complex<double> solve(const ComplexVariable &c);

} // namespace solver