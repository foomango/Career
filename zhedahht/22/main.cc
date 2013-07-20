/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/20/2013 07:35:39 PM
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
 * Get how many 1s in an integer's binary expression
 */
int NumberOf1Solution3(int i) 
{
    int count = 0;

    while (i) {
        ++count;
        i = (i - 1) & i;
    }

    return count;
}

int main(int argc, char* argv[]) 
{
    int i = 0xf0;

    printf("%d\n", NumberOf1Solution3(i));

    return 0;
}
