/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/17/2013 08:47:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstdlib>

/*
 * Print continuous sequence between small and big
 */
void PrintContinuousSequence(int small, int big) 
{
    for (int i = small; i <= big; ++i) {
        printf("%d ", i);
    }

    printf("\n");
}

/*
 * Find continuous sequence, whose sum is n
 */
void FindContinuousSequence(int n) 
{
    if (n < 3) {
        return;
    }

    int small = 1;
    int big = 2;
    int middle = (n - 1) / 2;
    int sum = small + big;

    while (small <= middle) {
        // we are lucky and find the sequence
        if (sum == n) {
            PrintContinuousSequence(small, big);
            sum -= small;
            ++small;
            ++big;
            sum += big;
        }
        // if the current sum is greater than n, 
        // move small forward
        else if (sum > n) {
            sum -= small;
            ++small;
        }
        // move big forward
        else {
            ++big;
            sum += big;
        }
    }
}

void usage(char* prog) 
{
    printf("Usage: %s num\n", prog);
}

int main(int argc, char* argv[]) 
{
    if (argc < 2) {
        usage(argv[0]);
        return -1;
    }

    int number = atoi(argv[1]);
    FindContinuousSequence(number);
    return 0;
}
