/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/13/2013 07:58:36 PM
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

const int N = 5;
const int M = 5 + 2;

bool IsValidRow(const string& str, int index, int max = 3) 
{
    int sum = 1;
    int left = index - 1;
    int right = index + 1;

    if (index < 0 || index >= str.size() || str.at(index) == '\0') 
        return false;

    while (left > 0 && str.at(index) == str.at(left)) {
        ++sum;
        --left;
    }

    while (right < str.size() && str.at(index) == str.at(right)) {
        ++sum;
        ++right;
    }

    return sum >= max;
}

bool IsValidColumn(const string& str, int index, int max = 3) 
{
    if (index < 0 || index >= str.size() || str.at(index) == '\0') 
        return false;
    int sum = 1;
    int up = index - M;
    int down = index + M;

    while ( up > 0 && str.at(index) == str.at(up)) {
        ++sum;
        up -= M;
    }

    while (down < str.size() && str.at(index) == str.at(down)) {
        ++sum;
        down += M;
    }

    return sum >= max;
}

int main(int argc, char *argv[]) 
{
    int index = -1;
    string s;
    cin >> s;

    string str;
    str += string(M, '\0');
    for (int i = 0; i <  N * N; i += N) {
        str += string(1, '\0') + s.substr(i, N) + string(1, '\0');
    }
    str += string(M, '\0');

    for (int i = 0; i < N * N; ++i) {
        int j = M + 1 + (i / N) * (M) + (i % N);

        // row
        swap(str.at(j), str.at(j + 1));
        if (IsValidRow(str, j) || IsValidColumn(str, j) || IsValidColumn(str, j + 1)) {
            index = i + 1;
            break;
        }
        swap(str.at(j), str.at(j + 1));

        // column
        swap(str.at(j), str.at(j + M));
        if (IsValidColumn(str, j) || IsValidRow(str, j) || IsValidRow(str, j + M)) {
            index = i + 1;
            break;
        }
        swap(str.at(j), str.at(j + M));

    }

    if (index != -1) {
        cout << "YES " << index << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
