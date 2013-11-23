/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/20/2013 12:03:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>

int main(int argc, char *argv[]) 
{
    char * const p = "abcd";
    std::cout << p << std::endl;
    p[1] = '2';
    std::cout << p << std::endl;
    return 0;
}
