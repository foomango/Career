/*
 * =====================================================================================
 *
 *       Filename:  bad_alloc.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/04/2013 10:40:09 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <cstdio>

int main(int argc, char *argv[]) 
{
    int *p = NULL;
    p = new int[9999999999999999990];
    printf("%x\n", p);
    return 0;
}
