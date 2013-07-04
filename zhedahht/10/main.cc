// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  06/04/2013 09:06:47 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>

/**
 * Find two numbers with a sum in a sorted array.
 * Output: true is found such numbers, otherwise false.
 **/
bool FindTwoNumbersWithSum(
        int* numbers,   // a sorted array
        int length,     // length of numbers
        int sum,        // the sum
        int& num1,      // the first number, output
        int& num2      // the second number, outpu
        ) 
{
    bool found = false;
    if (!numbers || length < 2) {
        return found;
    }

    int* begin = numbers;
    int* end = numbers + length - 1;
    while (begin < end) {
        int current_sum = *begin + *end;
        if (current_sum < sum) {
            begin++;
        } else if (current_sum > sum) {
            end--;
        } else {
            num1 = *begin;
            num2 = *end;
            found = true;
            break;
        }
    }

    return found;
}

void Test1() 
{
    int numbers[] = {1, 2, 4, 7, 11, 15};

    int num1 = 0;
    int num2 = 0;

    std::cout << FindTwoNumbersWithSum(numbers, sizeof(numbers) / sizeof(numbers[0]), 15, num1, num2); 
    std::cout << " " << num1 << " " << num2 << std::endl;
}

int main(int argc, char* argv[]) 
{
    Test1();
    return 0;
}
