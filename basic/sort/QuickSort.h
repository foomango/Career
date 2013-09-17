/*
 * =====================================================================================
 *
 *       Filename:  QuickSort.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/17/2013 10:47:01 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

template <typename T> 
class QuickSort {
public:
    typedef typename std::vector<T> vec;
    static void Sort(vec &a);

private:
    static void QuickSortCore(vec &a, int b, int e);
    static int Partition(vec &a, 
            int b, int e);
};

#endif
