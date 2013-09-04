/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  sizeof(string)
 *
 *        Version:  1.0
 *        Created:  08/31/2013 03:27:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main(int argc, char *argv[]) 
{
    string str("abcd");
    cout << sizeof(str) << endl;
    std::cout << sizeof(std::string) << std::endl;
    std::cout << sizeof(char*) << std::endl;
    return 0;
}
