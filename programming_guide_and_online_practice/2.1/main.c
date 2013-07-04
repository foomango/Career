/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/27/2013 08:25:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <stdio.h>
void main() 
{
    int nCases, i, nFeet;
    scanf("%d", &nCases);
    for (i = 0; i < nCases; i++) {
        scanf("%d", &nFeet);
        if (nFeet %2 != 0) {
            printf("0 0\n");
        } else if (nFeet % 4 == 0) {
            printf("%d %d\n", nFeet / 4, nFeet / 2);
        } else {
            printf("%d %d\n", (nFeet / 4) + 1, nFeet / 2);
        }
    }
}
