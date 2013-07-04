/*
 * =====================================================================================
 *
 *       Filename:  test.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/17/2013 10:22:56 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <stdio.h>

int main(int argc, char *argv[]) 
{
    long long sum;
    int a = 0x7fffffff;
    sum = (long long)a + a;
    printf("%lu %lu\n", sizeof(int), sizeof(long long));
    printf("%lld\n", sum);
    return 0;
}
