// =====================================================================================
// 
//       Filename:  test_genstack.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/14/2013 07:40:16 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <include/stack.h>

#include <iostream>
#include <stack>

int main(int argc, char* argv[]) 
{
    std::stack<int>* s = GenStack<int>();
    PrintStack(*s);
    return 0;
}
