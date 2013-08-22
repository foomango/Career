/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  http://foomango.blog.163.com/blog/static/218098074201372264738356/
 *
 *        Version:  1.0
 *        Created:  08/22/2013 06:49:33 PM
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

int AddWithoutArithmetic(int num1, int num2) 
{
    if (num2 == 0) {
        return num1;
    }

    int sum = num1 ^ num2;
    int carry = (num1 & num2) << 1;

    return AddWithoutArithmetic(sum, carry);
}

int main(int argc, char *argv[]) 
{
    int sum1 = atoi(argv[1]);
    int sum2 = atoi(argv[2]);
    int sum = AddWithoutArithmetic(sum1, sum2);
    printf("%d\n", sum);

    return 0;
}
