/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  Sum of n dices
 *
 *        Version:  1.0
 *        Created:  07/06/2013 08:27:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

int g_max_value = 6;

void SumProbabilityOfDices(int original, int current, int value, int temp_sum, int* pp) 
{
    assert(original >= 1);
    assert(current >= 1);
    assert(value >= 1 && value <= g_max_value);
    assert(temp_sum >= 0);
    assert(pp != NULL);

    if (current == 1) {
        int sum = value + temp_sum;
        pp[sum - original]++;
    }
    else {
        for (int i = 1; i <= g_max_value; i++) {
            SumProbabilityOfDices(original, current - 1, i, value + temp_sum, pp);
        }
    }
}

void SumProbabilityOfDices(int number, int* pp) 
{
    assert(number >= 1);
    assert(pp != NULL);

    for (int i = 1; i <= g_max_value; i++) {
        SumProbabilityOfDices(number, number, i, 0, pp);
    }
}

void PrintSumProbabilityOfDices_1(int number) 
{
    assert(number >= 1);

    int max_sum = number * g_max_value;
    int *pp = new int[max_sum - number + 1];
    for (int i = 0; i <= max_sum - number; i++) {
        pp[i] = 0;
    }

    SumProbabilityOfDices(number, pp);

    int total = pow((float)g_max_value, number);
    for (int i = number; i <= max_sum; i++) {
        float ratio = (float)pp[i - number] / total;
        printf("%d: %f [%d]\n", i, ratio, pp[i - number]);
    }
}

void PrintSumProbabilityOfDices_2(int number) 
{
    int* pp[2];
    pp[0] = new int[g_max_value * number + 1];
    pp[1] = new int[g_max_value * number + 1];
    // Initialize all to zero
    for (int i = 0; i < g_max_value * number + 1; i++) {
        pp[0][i] = 0;
        pp[1][i] = 0;
    }

    int flag = 0;
    // 初始化第一轮点数
    // Initialize the value of the first round
    for (int i = 1; i <= g_max_value; i++) {
        pp[flag][i] = 1;
    }

    for (int k = 2; k <= number; k++) {
        for (int i = k; i <= g_max_value * k; i++) {
            pp[1 - flag][i] = 0;

            // i - j要不小于上轮的最小值(k - 1)
            // i - j should be not smaller than last round's minimum value(k - 1)
            for (int j = 1; i - j >= k - 1 && j <= g_max_value; j++) {
                // i - j要不大于上轮的最大值((k - 1) * g_max_value)
                // i - j should be not larger than last round's maximum value((k - 1) * g_max_value)
                if (i - j > (k - 1) * g_max_value) {
                    printf("oops, %d\n", pp[flag][i - 1]);
                    continue;
                }
                // 由于本次的骰子由六种数字，所以本次第为i的点数由上次的
                // i - 1, i - 2, i - 3, i - 4, i - 5, i - 6组成
                pp[1 - flag][i] += pp[flag][i - j];
            }
        }
        flag = 1 - flag;
    }

    double total = pow((double)g_max_value, number);
    for (int i = number; i <= g_max_value * number; i++) {
        double ratio = pp[flag][i] / total;
        printf("%d: %f [%d]\n", i, ratio, pp[flag][i]);
    }

    delete[] pp[0];
    delete[] pp[1];
}

void usage(char* program) 
{
    printf("usage: %s number algrithom(1/2)\n", program);
}

int main(int argc, char* argv[]) 
{
    if (argc < 3) {
        usage(argv[0]);
        exit(1);
    }

    int number = atoi(argv[1]);
    if (number < 1) {
        usage(argv[0]);
        exit(1);
    }

    int algrithom = atoi(argv[2]);

    switch(algrithom) {
        case 1:
            PrintSumProbabilityOfDices_1(number);
            break;
        case 2:
            PrintSumProbabilityOfDices_2(number);
            break;
        default:
            usage(argv[0]);
            exit(1);
    }

    return 0;
}
