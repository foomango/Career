/*
 * =====================================================================================
 *
 *       Filename:  main2.cc
 *
 *    Description:  http://foomango.blog.163.com/blog/static/21809807420136259454337/
 *
 *        Version:  1.0
 *        Created:  07/25/2013 09:03:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <cstdio>

int GetMaxDiff(const int numbers[], int length) 
{
    if (numbers == NULL || length < 2) {
        return 1 << (sizeof(int) - 1);
    }

    int max = numbers[0];
    int max_diff = numbers[0] - numbers[1];

    for (int i = 2; i < length; ++i) {
        if (numbers[i - 1] > max) {
            max = numbers[i - 1];
        }

        int diff = max - numbers[i];

        if (diff > max_diff) {
            max_diff = diff;
        }
    }

    return max_diff;
}

int main(int argc, char* argv[]) 
{
    int length = 0;
    scanf("%d", &length);

    if (length < 2) {
        return -1;
    }

    int *numbers = new int[length];
    if (numbers == NULL) {
        return -2;
    }
    for (int i = 0; i < length; ++i) {
        scanf("%d", &numbers[i]);
    }

    int max_diff = GetMaxDiff(numbers, length);
    printf("%d\n", max_diff);

    delete[] numbers;

    return 0;
}
