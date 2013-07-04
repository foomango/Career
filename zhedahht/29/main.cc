// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  06/04/2013 08:20:35 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>

/**
 * Devide an array of integers into two parts, the intergers which statisfy func in the 
 * first part, otherwise in the second part.
 * Input:   numbers - an array of integers
 *          length - the length of numbers
 *          func - a function
 **/
void Reorder(int* numbers, int length, bool (*func)(int)) 
{
    if (!numbers || length < 2) {
        return;
    }

    int* begin = numbers;
    int* end = numbers + length - 1;

    while (begin < end) {
        // if *begin satisfies func, continue
        if (func(*begin)) {
            begin++;
            continue;
        }

        // if *end does not satisfy func, continue
        if (!func(*end)) {
            end--;
            continue;
        }

        // swap *begin and *end
        int temp = *begin;
        *begin = *end;
        *end = temp;
        begin++;
        end--;
    }
}

/**
 * Determine whether an integer is odd or not.
 * Input: n - an integer.
 * Output: if n is odd, return true, otherwise return false.
 **/
bool IsOdd(int n) 
{
    return n & 1;
}

/**
 * Devide an array of integers into two parts, add in the first part, 
 * and even in the second part.
 * Input:   numbers - an array of integers.
 *          length - length of numbers.
 **/
void ReorderOddEven(int* numbers, int length) 
{
    if (!numbers || length < 2) {
        return;
    }

    Reorder(numbers, length, IsOdd);
}

void Test1() 
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};

    ReorderOddEven(numbers, sizeof(numbers) / sizeof(numbers[0]));
    
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        std::cout << numbers[i] << "\t";
    }

    std::cout << std::endl;
}

int main(int argc, char* argv[]) 
{
    Test1();
    return 0;
}
