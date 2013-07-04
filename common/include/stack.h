// =====================================================================================
// 
//       Filename:  stack.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/14/2013 07:19:40 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#ifndef STACK_H
#define STACK_H

#include <stack>
#include <iostream>

template<typename T> std::stack<T>* GenStack();
template<typename T> void PrintStack(const std::stack<T>& stack);

template<typename T> std::stack<T>* GenStack() 
{
    std::stack<T>* pStack = new std::stack<T>();
    if (!pStack) {
            return NULL;
        }

    T elem;

    while (std::cin >> elem) {
            pStack->push(elem);
        }

    return pStack;
}

template<typename T> void PrintStack(std::stack<T>& stack) 
{
    std::cout << std::endl;
    while (!stack.empty()) {
            const T& elem = stack.top();
            std::cout << elem << " ";
            stack.pop();
        }
    std::cout << std::endl;
}

#endif
