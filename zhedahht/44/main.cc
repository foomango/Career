// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  06/12/2013 07:43:39 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>
#include <limits>

bool g_invalid_input = false;

double PowerWithUnsignedExponent1(double base, unsigned int exponent) 
{
    double power = 1.0;
    double index_power = base;
    unsigned index = exponent;

    while (index) {
        if (index & 1) {
            power *= index_power;
        }
        index_power *= index_power;

        index >>= 1;
    }

    return power;
}

double PowerWithUnsignedExponent2(double base, unsigned int exponent) 
{
    if (exponent == 1) {
        return base;
    }

    if (exponent == 0) {
        return 1.0;
    }

    double power = PowerWithUnsignedExponent2(base, exponent >> 1);
    power *= power;

    if (exponent & 1) {
        power *= base;
    }

    return power;
}

bool IsZero(double number) 
{
    return number < std::numeric_limits<double>::epsilon() && 
        number > -std::numeric_limits<double>::epsilon();
}

double Power(double base, int exponent) 
{
    g_invalid_input = false;
    if (IsZero(base) && exponent <= 0) {
        g_invalid_input = true;
        return 0.0;
    }

    if (exponent < 0) {
        return 1.0 / PowerWithUnsignedExponent1(base, -exponent);
    } else {
        return PowerWithUnsignedExponent1(base, exponent);
    }
}

int main(int argc, char* argv[]) {
    std::cout << PowerWithUnsignedExponent1(1.1, 32) << std::endl;
    std::cout << PowerWithUnsignedExponent2(1.1, 32) << std::endl;

    return 0;
}
