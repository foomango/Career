// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/15/2013 09:19:45 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <CStackWithMin.h>

void testCase1() 
{
    CStackWithMin<int> stack;

    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(3);
    stack.push(1);
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
}

int main(int argc, char* argv[]) 
{
    testCase1();

    return 0;
}
