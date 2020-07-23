#include "solver.hpp"
#include "RealVariable.hpp"
#include "ComplexVariable.hpp"

namespace solver
{
double solve(const RealVariable &r)
{
    // std::cout << r << " = 0" << std::endl;
    double x1, x2, discriminant;

    if (r._degree == 0)
    {
        throw std::logic_error("No real solution to function");
    }
    else if (r._degree == 1)
    {
        return -r._c / r._b;
    }

    discriminant = r._b * r._b - 4.0 * r._a * r._c;

    if (discriminant > 0)
    {
        x1 = (-r._b + sqrt(discriminant)) / (2 * r._a);
        x2 = (-r._b - sqrt(discriminant)) / (2 * r._a);
    }
    else if (discriminant == 0)
    {
        x1 = (-r._b + sqrt(discriminant)) / (2 * r._a);
    }
    else
    {
        throw std::logic_error("No real solution to function");
    }

    return x1;
}

std::complex<double> solve(const ComplexVariable &c)
{
    // std::cout << r << " = 0" << std::endl;
    std::complex<double> x1, x2, discriminant;

    if (c._degree == 0)
    {
        throw std::logic_error("No real solution to function");
    }
    else if (c._degree == 1)
    {
        return -c._c / c._b;
    }
    else
    {
        discriminant = c._b * c._b - 4.0 * c._a * c._c;
        x1 = (-c._b + sqrt(discriminant)) / (2.0 * c._a);
        x2 = (-c._b - sqrt(discriminant)) / (2.0 * c._a);
    }

    return x1;
}

} // namespace solver