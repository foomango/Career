/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/29/2013 11:26:21 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>

using std::cout;
using std::endl;

const int N = 10;
int num[N];

void GetProbability(int& total, int& result, int index, int level) 
{
    if (index == level) {
        ++total;
        if (num[index] == 0) {
            ++result;
        }
        return;
    }

    if (num[level] == 0) {
        num[level] = 1;
        GetProbability(total, result, index, level + 1);
        num[level] = 0;
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (num[i] == 0) {
            num[i] = 1;
            GetProbability(total, result, index, level + 1);
            num[i] = 0;
        }
    }
}

void GetProbability(int& total, int& result, int index) 
{
    if (index < 1) {
        return;
    }

    for (int i = 0; i < N; ++i) {
        num[i] = 1;
        GetProbability(total, result, index, 1);
        num[i] = 0;
    }
}

int main(int argc, char *argv[]) 
{
    int total = 0;
    int result = 0;
    int index = 9;

    GetProbability(total, result, index);

    cout << result << "/" << total << endl;

    return 0;
}
