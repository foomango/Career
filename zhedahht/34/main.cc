// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/21/2013 07:58:41 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>

inline int FindFirstBitIs1(int num) __attribute__((always_inline));

/**
 * Find first bit which is 1 in num
 **/
inline int FindFirstBitIs1(int num) 
{
    return num & (~num + 1);
    //return (num & ~(num - 1));
}

/**
 * Find two numbers which only appear once in an array
 * Input: data - an array contains two numbers appearing exactly once.
 *        length - the length of data
 * Output: num1 - the first number appearing once in data
 *         num2 - the second number appearing once in data
 **/
void FindNumsAppearOnce(int data[], int length, int& num1, int& num2) 
{
    if (!data || length < 2)
        return;

    // get num1 ^ num2
    int resultExclusiveOR = 0;
    for (int i = 0; i < length; i++) {
        resultExclusiveOR ^= data[i];
    }

    int firstBitIs1 = FindFirstBitIs1(resultExclusiveOR);
    num1 = 0;
    num2 = 0;
    for (int i = 0; i < length; i++) {
        // divide the numbers in data into two groups, 
        // the result of nums & firstBitIs1 in the first group is not 0, 
        // while in the second group is 0
        if (firstBitIs1 & data[i]) {
            num1 ^= data[i];
        }
        else {
            num2 ^= data[i];
        }
    }
}

int main(int argc, char* argv[]) 
{
    int length;
    std::cin >> length;

    int *pData = new int[length];
    if (!pData) 
        return -1;

    for (int i = 0; i < length; i++) {
        std::cin >> pData[i];
    }

    int num1, num2;

    FindNumsAppearOnce(pData, length, num1, num2);

    std::cout << num1 << " " << num2 << std::endl;

    return 0;
}
