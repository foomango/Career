/*
 * =====================================================================================
 *
 *       Filename:  execl.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/20/2013 08:16:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <unistd.h>
int main(void)
{
    printf("call execl"); 
    sleep(1); 
    execl("/bin/ls", "", NULL); 
    printf("error!\n");
}
