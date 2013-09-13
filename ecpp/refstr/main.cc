/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2013 04:33:56 PM
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

using namespace std;

int main(int argc, char *argv[]) 
{
    string s("abc");
    s[0] = 'b';

    cout << s << endl;
    return 0;
}
