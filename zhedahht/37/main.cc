/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/17/2013 07:27:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdlib>

unsigned long long Min(unsigned long long  number1, unsigned long long number2, unsigned long long number3) 
{
    unsigned long long min = (number1 < number2) ? number1 : number2;
    min = (min < number3) ? min : number3;

    return min;
}

void CheckValid(unsigned long long  *numbers, int length) {
    for (int i = 0; i < length - 1; ++i) {
        if (numbers[i] >= numbers[i + 1]) {
            std::cout << "overflow" << std::endl;
            exit(-1);
        }
    }
}

unsigned long long GetUglyNumberSolution2(int index) 
{
    if (index <= 0) {
        return 0;
    }

    unsigned long long *pugly_numbers = new unsigned long long[index];
    pugly_numbers[0] = 1;
    int next_ugly_index = 1;

    unsigned long long *pmultiply2 = pugly_numbers;
    unsigned long long *pmultiply3 = pugly_numbers;
    unsigned long long *pmultiply5 = pugly_numbers;

    while (next_ugly_index < index) {
        unsigned long long min = Min(*pmultiply2 * 2, *pmultiply3 * 3, *pmultiply5 * 5);

        pugly_numbers[next_ugly_index] = min;

        while (*pmultiply2 * 2 <= pugly_numbers[next_ugly_index]) {
            ++pmultiply2;

            // Overflow
            if (pmultiply2 > &pugly_numbers[next_ugly_index]) {
                delete[] pugly_numbers;
                return 0;
            }
        }
        while (*pmultiply3 * 3 <= pugly_numbers[next_ugly_index]) {
            ++pmultiply3;

            // Overflow
            if (pmultiply3 > &pugly_numbers[next_ugly_index]) {
                delete[] pugly_numbers;
                return 0;
            }
        }
        while (*pmultiply5 * 5 <= pugly_numbers[next_ugly_index]) {
            ++pmultiply5;

            // Overflow
            if (pmultiply5 > &pugly_numbers[next_ugly_index]) {
                delete[] pugly_numbers;
                return 0;
            }
        }

        ++next_ugly_index;
    }

    CheckValid(pugly_numbers, index);

    unsigned long long ugly = pugly_numbers[next_ugly_index - 1];
    delete[] pugly_numbers;

    return ugly;
}

int main(int argc, char* argv[]) 
{
    const int index = 12001;
    unsigned long long ugly = GetUglyNumberSolution2(index);

    std::cout << ugly << std::endl;
    return 0;
}
