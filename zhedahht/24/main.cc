// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/14/2013 09:10:37 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>
#include <stack>

/**
 * Given a push order of a stack, determine whether an array is possible to
 * be its corresponding pop order
 * Input:   pPush       - an array of integers, the push order
 *          pPop        - an array of integers, the pop order
 *          nLength     - the length of pPush and pPop
 * Output:  If pPop is possible to be the pop order of pPush, return true.
 *          Otherwise return false.
 **/
bool IsPossiblePopOrder(const int* pPush, const int* pPop, int nLength) 
{

    if (pPush && pPop && nLength > 0) {
        const int* pNextPush = pPush;
        const int* pNextPop = pPop;

        // ancillary stack
        std::stack<int> stackData;

        while (pNextPush < pPush + nLength) {
            if (stackData.empty() || stackData.top() != *pNextPop) {
                std::cout << "push " << *pNextPush << std::endl;
                stackData.push(*(pNextPush++));
            } else {
                stackData.pop();
                std::cout << "pop  "<< *pNextPop << std::endl;
                pNextPop++;
            }
        }

        while (!stackData.empty()) {
            if (stackData.top() != *pNextPop) {
                return false;
            } else {
                stackData.pop();
                std::cout << "pop  "<< *pNextPop << std::endl;
                pNextPop++;
            }
        }

        return true;
    }
}

int main(int argc, char* argv[]) 
{
    const int len = 5;
    const int pPush[len] = {1, 2, 3, 4, 5};
    const int pPop[len] = {4, 5, 3, 2, 1};
    //const int pPop[len] = {4, 3, 5, 1, 2};

    bool bPossible = IsPossiblePopOrder(pPush, pPop, len);
    std::cout << std::endl << bPossible << std::endl;

    return 0;
}
