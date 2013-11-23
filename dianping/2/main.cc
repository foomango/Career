/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/22/2013 03:20:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>
#include <cmath>

using namespace std;

char GetChar(int i) 
{
    char ret = 'G';

    if (i <= 0) 
        return ret;

    int n = sqrt(2 * i);
    ret = n * (n + 1) / 2 - i;

    if (ret > 0 && ret < 10) {
        ret += '0';
    }
    else if (ret >= 10 && ret <= 15){
        ret = ret - 10 + 'A';
    }
    else {
        ret = 'G';
    }

    return ret;
}

int main(int argc, char *argv[]) 
{
    cout << GetChar(50) << endl;
    return 0;
}
