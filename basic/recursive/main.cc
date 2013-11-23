/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/18/2013 03:39:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

void recursive() 
{
    int temp[10000000];
    recursive();
}

int main(int argc, char* argv[]) 
{
    recursive();
    return 0;
}
