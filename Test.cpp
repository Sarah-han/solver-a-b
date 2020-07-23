/**
 * AUTHORS: <Raphael Gozlan, Sarah Hananayev>
 *
 * Date: 2020-04
 */
#include "doctest.h"
#include "solver.hpp"

using solver::solve, solver::RealVariable, solver::ComplexVariable;

RealVariable x;

TEST_CASE("Test For RealVariable on the power of 2")
{
    CHECK(solve((x ^ 2) == 9) == 3);
    CHECK(solve((x ^ 2) == 64 == 8));
    CHECK(solve((x ^ 2) == 100) == 10);
    CHECK(solve((x ^ 2) == 4) == 2);
    CHECK(solve((x ^ 2) == 25) == 5);
    CHECK(solve((x ^ 2) == 16) == 4);
    CHECK(solve((x ^ 2) == 36) == 6);
    CHECK(solve((x ^ 2) == 9) == 3);
    CHECK(solve((x ^ 2) == 81) == 9);
    CHECK(solve((x ^ 2) == 121) == 11);
    CHECK(solve((x ^ 2) == 196) == 14);
    CHECK(solve((x ^ 2) == 44) == 12);
    CHECK(solve((x ^ 2) == 6241) == 79);
    CHECK(solve((x ^ 2) == 2401) == 49);
    CHECK(solve((x ^ 2) == 4356) == 66);
    CHECK(solve((x ^ 2) == 10000) == 100);
    CHECK(solve((x ^ 2) == 9801) == 99);
    CHECK(solve((x ^ 2) == 3136) == 56);
    CHECK(solve((x ^ 2) == 0) == 0);
    CHECK(solve((x ^ 2) == 1681) == 41);
    CHECK(solve((x ^ 2) == 1000000) == 1000);
    CHECK(solve((x ^ 2) == 25921) == 161);
    CHECK(solve((x ^ 2) == 8281) == 91);
    CHECK(solve((x ^ 2) == 2704) == 52);
    CHECK(solve((x ^ 2) == 4096) == 64);
    CHECK(solve((x ^ 2) == 12996) == 114);
    CHECK(solve((x ^ 2) == 1234321) == 1111);
    CHECK(solve((x ^ 2) == 361) == 19);

    CHECK(solve(2 * x - 2 == 10) == 8);
    CHECK(solve(15 * x - 5 * x == 10) == 1);
    CHECK(solve(2 * x - 3 * x == 10) == -10);
    CHECK(solve(1000 * x - 2900 == 100) == 3);
    CHECK(solve(6 * x - 2 + 3 * x + x + 42 == 10) == -3);
    CHECK(solve(9 * x == 18) == 2);
    CHECK(solve(7 * x + 11 - x == 10 + 7) == 1);
    CHECK(solve(49 * x == 343) == 7);
    CHECK(solve(x - 15 == 8) == -23);
    CHECK(solve(-3 * (-1 * x - 7) == 8 * x) == 4.5);
    CHECK(solve(3 * x / 0.5 * x) == 6);
    CHECK(solve(6 * x / 0.5 * x) == 12);
    CHECK(solve(8 * x / 2 * x) == 4);
    CHECK(solve(27 * x / 3 * x) == 9);
    CHECK(solve((7 * x ^ 2) == 7) == 1);
    CHECK(solve((11 * x ^ 2) + 121 == 121) == 0);
    CHECK(solve((20 * x ^ 2) + 100 == 420) == 4);
    CHECK((solve(3 * (x ^ 2) + 22 * x + 57 == (x ^ 2) - 3) == -5 || solve(3 * (x ^ 2) + 22 * x + 57 == (x ^ 2) - 3) == -6));
    CHECK((solve((-1 * x ^ 2) + 6 * x - 4 == -2 * (x ^ 2) - 4) == -9 || solve((-1 * x ^ 2) + 6 * x - 4 == -2 * (x ^ 2) - 4) == 0));
    CHECK((solve(2 * (x ^ 2) + 4 * x - 21 == -4 * x + 3) == -6 || solve(2 * (x ^ 2) + 4 * x - 21 == -4 * x + 3) == 2));
    CHECK((solve(2 * (x ^ 2) + 14 * x + 15 == 3) == -6 || solve(2 * (x ^ 2) + 14 * x + 15 == 3) == -1));
    CHECK((solve(6 * (x ^ 2) + 6 * x + 4 == 4 * (x ^ 2) + 2 * x + 4) == -2 || solve(6 * (x ^ 2) + 6 * x + 4 == 4 * (x ^ 2) + 2 * x + 4) == 0));
    CHECK((solve((x ^ 2) + 5 * x + 7 == -1 * x - 1) == -2 || solve((x ^ 2) + 5 * x + 7 == -1 * x - 1) == -4));
    CHECK((solve((x ^ 2) + 6 * x + 9 == 1) == -2 || solve((x ^ 2) + 6 * x + 9 == 1) == -4));
    CHECK((solve(2 * (x ^ 2) - 15 * x + 34 == x + 4) == 5 || solve(2 * (x ^ 2) - 15 * x + 34 == x + 4) == 3));
    CHECK((solve((x ^ 2) - 1 * x - 5 == 1) == -2 || solve((x ^ 2) - 1 * x - 5 == 14) == 3));
    CHECK((solve((-1 * x ^ 2) + 22 * x + 56 == -3 * (x ^ 2) - 4) == -6 || solve((-1 * x ^ 2) + 22 * x + 56 == -3 * (x ^ 2) - 4) == -5));
}

TEST_CASE("Test for unsolvable function")
{
    CHECK_THROWS(solve(0 * x == 1));
    CHECK_THROWS(solve(0 * x == 2346789));
    CHECK_THROWS(solve(0 * x == 686868));
    CHECK_THROWS(solve(0 * x == 9));
    CHECK_THROWS(solve(0 * x == 166));
    CHECK_THROWS(solve(0 * x == 15));
    CHECK_THROWS(solve(0 * x == 551));
    CHECK_THROWS(solve(0 * x == 2346678789));
    CHECK_THROWS(solve(0 * x == 68996868));
    CHECK_THROWS(solve(0 * x == 11));
    CHECK_THROWS(solve(0 * x == 23467189));
    CHECK_THROWS(solve(0 * x == 6868168));
    CHECK_THROWS(solve(0 * x == 91));
    CHECK_THROWS(solve(0 * x == 1616));
    CHECK_THROWS(solve(0 * x == 23466178789));
    CHECK_THROWS(solve(0 * x == 689961868));
    CHECK_THROWS(solve(0 * x == 9100));
    CHECK_THROWS(solve(0 * x == 1699816));
    CHECK_THROWS(solve(0 * x == 17778915));
    CHECK_THROWS(solve(3 * x - 3 * x == 1));
    CHECK_THROWS(solve(376 * x - 376 * x == 2346789));
    CHECK_THROWS(solve(36 * x - 36 * x == 686868));
    CHECK_THROWS(solve(0 * x == 115));
    CHECK_THROWS(solve(0 * x == 5151));
    CHECK_THROWS(solve(8883 * x - 8883 * x == 9));
    CHECK_THROWS(solve(37 * x - 37 * x == 166));
    CHECK_THROWS(solve(0 * x == 900));
    CHECK_THROWS(solve(9 * x - 9 * x == 15));
    CHECK_THROWS(solve((x ^ 2) == -1));
    CHECK_THROWS(solve((x ^ 2) == -2346789));
    CHECK_THROWS(solve((x ^ 2) == -686868));
    CHECK_THROWS(solve((x ^ 2) == -9));
    CHECK_THROWS(solve((x ^ 2) == -166));
    CHECK_THROWS(solve((x ^ 2) == -15));
    CHECK_THROWS(solve((x ^ 2) + 4 == (x ^ 2) + 4 - 166));
    CHECK_THROWS(solve((x ^ 2) == (x ^ 2) - 15));
    CHECK_THROWS(solve(8883 * x == 8883 * x + 9));
    CHECK_THROWS(solve(37 * x == 37 * x + 166));
    CHECK_THROWS(solve(9 * x == 9 * x - 15));
    CHECK_THROWS(solve((5 * x ^ 2) + 4 == (5 * x ^ 2) + 4 - 166));
    CHECK_THROWS(solve((55 * x ^ 2) == (55 * x ^ 2) - 15));
    CHECK_THROWS(solve(888553 * x == 888553 * x + 9));
    CHECK_THROWS(solve(37 * x == 37 * x + 1655556));
    CHECK_THROWS(solve(9 * x == 9 * x - 15555555555));
    CHECK_THROWS(solve(0 * x == 169986));
    CHECK_THROWS(solve(0 * x == 1777895));
}

TEST_CASE("Test the function with ComplexVariable")
{
    ComplexVariable y;
    CHECK((solve(y^2)-4*y==8*y-11)==std::complex<double> (0,11) || solve((y^2)-4*y==8*y-11)==std::complex<double> (0,1)));
    CHECK((solve(y^2)+6*y+13==0)==std::complex<double> (-3,2) || solve((y^2)+6*y+13==0)==std::complex<double> (-3,-2)));
    CHECK((solve(y^2)+6*y+34==0)==std::complex<double> (-3,-5) || solve((y^2)+6*y+34==0)==std::complex<double> (-3,5) ));
    CHECK((solve(y^2)+2*y+50==0)==std::complex<double> (-1,-7) || solve((y^2)+2*y+50==0)==std::complex<double> (-1,7) ));
    CHECK((solve(y^2)+2*y+30==-35)==std::complex<double> (-1,-8) || solve((y^2)+2*y+30==-35)==std::complex<double> (-1,8) ));
    CHECK((solve(y^2)+2*y+3==1)==std::complex<double> (-1,-1) || solve((y^2)+2*y+3==1)==std::complex<double> (-1,1) ));
    CHECK((solve(y^2)+4*y+20==7)==std::complex<double> (-2,-3) || solve((y^2)+4*y+20==7)==std::complex<double> (-2,3) ));
    CHECK((solve(y^2)+4*y+5==0)==std::complex<double> (-2,1) || solve((y^2)+4*y+5==0)==std::complex<double> (-2,-1) ));
    CHECK((solve(y^2)+4*y+13==-27)==std::complex<double> (-2,6) || solve((y^2)+4*y+13==-27)==std::complex<double> (-2,-6) ));
    CHECK((solve(y^2)+2*y+53==-2*y)==std::complex<double> (-2,7) || solve((y^2)+2*y+53==-2*y)==std::complex<double> (-2,-7) ));
    CHECK((solve((y ^ 2) == -4) == std::complex<double>(0, 2) || solve((y ^ 2) == -4) == std::complex<double>(0, -2)));
    CHECK((solve((y ^ 2) + 100 == 0) == std::complex<double>(0, 10) || solve((y ^ 2) + 100 == 0) == std::complex<double>(0, -10)));
    CHECK((solve((y ^ 2) + 4 * y + 5 == 0) == std::complex<double>(-2, 1) || solve((y ^ 2) + 4 * y + 5 == 0) == std::complex<double>(-2, -1)));
    CHECK((solve((2 * y ^ 2) - 6 * y + 5 == 0) == std::complex<double>(1.5, 0.5) || solve((2 * y ^ 2) - 6 * y + 5 == 0) == std::complex<double>(1.5, -0.5)));
    CHECK((solve(7 * y - std::complex<double>(13, 1) == 47 + std::complex<double>(3, 1) * y) == std::complex<double>(5, -4)));
}
