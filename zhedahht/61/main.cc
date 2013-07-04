// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/22/2013 08:47:43 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>
#include <limits>

#include <assert.h>

int maxDiffCore(const int* start, const int* end, int& max, int& min) 
{
    assert(start <= end);
    if (start == end) {
        max = min = *start;
        return std::numeric_limits<int>::min();
    }

    const int* middle = start + (end - start) / 2;

    int maxLeft, minLeft;
    int maxDiffLeft = maxDiffCore(start, middle, maxLeft, minLeft);

    int maxRight, minRight;
    int maxDiffRight = maxDiffCore(middle + 1, end, maxRight, minRight);

    int crossDiff = maxLeft - minRight;

    max = maxLeft < maxRight ? maxRight : maxLeft;
    min = minLeft < minRight ? minLeft : minRight;

    int maxDiff = maxDiffRight > maxDiffLeft ? maxDiffRight : maxDiffLeft;
    maxDiff = maxDiff > crossDiff ? maxDiff : crossDiff;

    return maxDiff;
}

int maxDiffSolution1(const int numbers[], int length) 
{
    if (!numbers || length < 2) {
        return -1;
    }

    int max, min;
    return maxDiffCore(numbers, numbers + length - 1, max, min);
}

int MaxDiffSolution2(const int numbers[], int length) {
    if (!numbers || length < 2) {
        return std::numeric_limits<int>::min();
    }

    int *diff = new int[length - 1];

    for (int i = 0; i < length - 1; i++) {
        diff[i] = numbers[i] - numbers[i + 1];
    }

    int currentSum = 0;
    int greatestSum = std::numeric_limits<int>::min();
    for (int j = 0; j < length - 1; j++) {
        if (currentSum < 0) {
            currentSum = diff[j];
        } else {
            currentSum += diff[j];
        }

        if (currentSum > greatestSum) {
            greatestSum = currentSum;
        }
    }

    delete diff;

    return greatestSum;
}

int MaxDiffSolution3(const int numbers[], int length) 
{
    int maxDiff = std::numeric_limits<int>::min();

    if (!numbers || length < 2) {
        return maxDiff;
    }

    int max = numbers[0];
    for (int i = 1; i < length; i++) {
        int diff = max - numbers[i];
        // numbers[i] is greater than max
        if (diff < 0) {
            max = numbers[i];
        }

        if (maxDiff < diff) {
            maxDiff = diff;
        }
    }

    return maxDiff;
}

typedef int (*fn_t)(const int numbers[], int length);
fn_t fns[] = {maxDiffSolution1, MaxDiffSolution2, MaxDiffSolution3};

int main(int argc, char* argv[]) 
{
    int length = 0;

    std::cin >> length;
    int* numbers = new int[length];
    if (!numbers) {
        return -1;
    }

    for (int i = 0; i < length; i++) {
        std::cin >> numbers[i];
    }

    for (int j = 0; j < sizeof(fns) / sizeof(fns[0]); j++) {
        int maxDiff = fns[j](numbers, length);
        std::cout << maxDiff << std::endl;
    }

    return 0;
}
