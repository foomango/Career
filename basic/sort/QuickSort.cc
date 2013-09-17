/*
 * =====================================================================================
 *
 *       Filename:  QuickSort.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/17/2013 10:44:53 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

#include "QuickSort.h"

using namespace std;

template <typename T>
void QuickSort<T>::Sort(vec &a) 
{
    QuickSortCore(a, 0, a.size() - 1);
}

template <typename T>
void QuickSort<T>::QuickSortCore(vec &a, int b, int e) 
{
    if (b < e) {
        int m = Partition(a, b, e);
        QuickSortCore(a, b, m - 1);
        QuickSortCore(a, m + 1, e);
    }
}

template <typename T> 
int QuickSort<T>::Partition(vec &a, int b, int e) 
{
    int i = b - 1;
    int j = b;
    T x = a[e];
    while (j < e) {
        if (a[j] <= x) {
            swap(a[i + 1], a[j]);
            ++i;
        }
        ++j;
    }

    swap(a[i + 1], a[e]);

    return i + 1;
}

int main(int argc, char *argv[]) 
{
    int a[] = {2, 3, 1, 9, 4};
    vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

    QuickSort<int>::Sort(v);

    for (int i = 0; i < v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;

    return 0;
}
