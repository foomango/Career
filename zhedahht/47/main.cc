// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  06/02/2013 12:38:47 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>

bool g_input_invalid = false;

/**
 * Input: An array with <code> length </code> numbers. A number in the array appears more 
 *        than <code> length </code> / 2 + 1 times.
 * Output: If the input is valid, return the number appearing more than <code> length </code>
 *         / 2 + 1 times. Otherwise, return 0 and set flag g_input_invalid to be ture.
 **/
int MoreThanHalfNum(int* numbers, int length) 
{
    if (!numbers || length <= 0) {
        g_input_invalid = true;
        return 0;
    }

    g_input_invalid = false;

    int result = numbers[0];
    int times = 1;
    for (int i = 1; i < length; i++) {
        if (times == 0) {
            result = numbers[i];
            times = 1;
        } else if (numbers[i] == result) {
            times++;
        } else {
            times--;
        }
    }

    // varify whether the input is valid
    times = 0;
    for (int i = 0; i < length; i++) {
        if (numbers[i] == result) {
            times++;
        }
    }

    if (times < (length / 2) + 1) {
        g_input_invalid = true;
        result = 0;
    }

    return result;
}

void Test1() 
{
    int numbers[] = {1, 2, 3, 2, 4, 2, 2, 5, 2, 2, 2, 9, 1};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    int result = MoreThanHalfNum(numbers, length);

    std::cout << result << std::endl;
}

int main(int argc, char* argv[]) 
{
    Test1();

    return 0;
}
