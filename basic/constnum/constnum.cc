/*
 * =====================================================================================
 *
 *       Filename:  constnum.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/08/2013 08:59:47 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

enum Status {a, b=0x800000000000000};

int main(int argc, char *argv[]) 
{
    unsigned int m = 0x80000000;
    double d = 2.2;
    int *p = reinterpret_cast<int*>(&d);
    cout << *p << endl;
    cout << static_cast<int>(0x80000000) << endl;
    cout << -1 << endl;
    cout << "sizeof(long):" << sizeof(long) << endl;
    cout << "sizeof(Status):" << sizeof(Status) << endl;
    cout << b << endl;
    return 0;
}
