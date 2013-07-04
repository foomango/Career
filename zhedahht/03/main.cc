// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  06/04/2013 09:27:21 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>

/**
 * Find the greatest sum of all sub-arrays
 * Output: if the input is valid, return true, otherwise return false.
 **/
bool FindGreatestSumOfSubArray
(
 int* numbers,      // an array
 int length,        // length of numbers
 int& greatest_sum  // the greatest sum of all sub-arrays.
 )
{
    bool found = false;
    if (!numbers || length < 1) {
        return found;
    }

    int current_sum = numbers[0];
    greatest_sum = numbers[0];

    for (int i = 1; i < length; i++) {
        if (current_sum < 0) {
            current_sum = numbers[i];
        } else {
            current_sum += numbers[i];
        }

        if (current_sum > greatest_sum) {
            greatest_sum = current_sum;
        }
    }

    return true;

}

void Test1() 
{
    int numbers[] = {1, -2, 3, 10, -4, 7, 2, -5};
    int greatest_sum = 0;

    std::cout << FindGreatestSumOfSubArray(numbers, sizeof(numbers) / sizeof(numbers[0]), greatest_sum);
    std::cout << " " << greatest_sum << std::endl;;
}

int main(int argc, char* argv[]) 
{
    Test1();

    return 0;
}
