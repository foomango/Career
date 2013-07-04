// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/14/2013 07:18:31 PM
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

/**
 * Add an element to the bottom of a stack
 **/
template<typename T> void AddToStackBottom(std::stack<T>& stack, T t) 
{
   if (stack.empty()) {
       stack.push(t);
   } else {
       T top = stack.top();
       stack.pop();
       AddToStackBottom(stack, t);
       stack.push(top);
   }
}

/**
 * Reverse a stack recursively in three steps:
 * 1. Pop the top element
 * 2. Reverse the remaining stack
 * 3. Add the top element to the bottom of the remaining stack
 **/
template<typename T> void ReverseStack(std::stack<T>& stack) 
{
    if (!stack.empty()) {
        T top = stack.top();
        stack.pop();
        ReverseStack(stack);
        AddToStackBottom(stack, top);
    }
}

int main(int argc, char* argv[]) 
{
    std::stack<int>* pStack = GenStack<int>();
    std::cout << std::endl << "Before reversing:" << std::endl;
    std::stack<int> t = *pStack;
    PrintStack(t);

    ReverseStack(*pStack);
    std::cout << std::endl << "After reversing:" << std::endl;
    PrintStack(*pStack);

    std::cout << std::endl;
}
