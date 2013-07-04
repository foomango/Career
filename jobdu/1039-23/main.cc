/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/16/2013 09:35:19 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <stdio.h>

int array[1000000];

int FindTwoNumbersWithSum(
        int array[], 
        int length, 
        long long sum, 
        int &num1, 
        int &num2) 
{
    int left, right;
    
    left = 0;
    right = length -1;
    long long product1 = (long long)array[left] * array[left];
    long long product2 = (long long)array[right] * array[right];
    long long product = product1 > product2 ? product1 : product2;

    while (left < right) {
        long long cursum = (long long)array[left] + (long long)array[right];

        if (cursum < sum) {
            left++;
        } else if (cursum > sum) {
            right--;
        } else {
            long long newproduct = (long long)array[left] * (long long)array[right];
            if (product > newproduct) {
                num1 = array[left];
                num2 = array[right];
                product = newproduct;
            }
            left++;
            right--;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) 
{
    int length;
    long long sum;
    while (scanf("%d", &length) != EOF) {
        scanf("%lld", &sum);
        for (int i = 0; i < length; i++) {
            scanf("%d", &array[i]);
        }
        int num1 = -1;
        int num2 = -1;
        FindTwoNumbersWithSum(array, length, sum, num1, num2);
        printf("%d %d\n", num1, num2);
    }

    return 0;
}
