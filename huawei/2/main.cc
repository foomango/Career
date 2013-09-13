/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/13/2013 07:25:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>

using namespace std;

const int Mask = 0x3ffffff;

int Name2Int(const string& name) 
{
    int ret = 0;
    for (int i = 0; i < name.size() || ret & Mask != Mask; ++i) {
        int index = name.at(i) - 'a';
        if (index < 0 || index > 25) 
            continue;
        ret |= 1 << index;
    }

    return ret;
}

int NumOf1(int num) 
{
    int n = num;
    int ret = 0;

    while(n != 0) {
        n &= n - 1;
        ++ret;
    }

    return ret;
}

int main(int argc, char *argv[]) 
{

    string name;
    getline(cin, name);
    int index = Name2Int(name);

    string females[] = {
        "wang fei",
        "zhang man yu",
        "zhang zhi yi",
        "li li",
        "li xiao man",
        "li yu cun",
        "yang ni",
        "xiao tong",
        "li lei",
        "zhang san"
    };

    int maxIndex = 0;
    int max = NumOf1(index & Name2Int(females[0]));
    for (int i = 1; i < sizeof(females) / sizeof(females[0]); ++i) {
        int curMax = NumOf1(index & Name2Int(females[i]));
        if (curMax > max) {
            max = curMax;
            maxIndex = i;
        }
    }

    cout << females[maxIndex] << endl;
    return 0;
}
