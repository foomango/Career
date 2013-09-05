/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/04/2013 09:22:09 PM
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
    int i = 0;
    //++(i++);
    (++i)++;
    std::cout << i << std::endl;
    
    return 0;
}
