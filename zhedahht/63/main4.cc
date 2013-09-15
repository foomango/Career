// =====================================================================================
// 
//       Filename:  main4.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  07/24/2013 10:45:52 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <cstdio>
#include <vector>

using std::vector;
using std::swap;

inline int FirstBitOf1(int number) 
{
    return number & -number;
}

void GetTwoUnique(vector<int>::iterater begin, 
        vector<int>::iterator end, vector<int>& unique) 
{
    // Get xor result
    int xor_result = 0;
    for (vector<int>::iterator iter = begin; 
            iter != end; ++iter) {
        xor_result ^= *iter;
    }

}
