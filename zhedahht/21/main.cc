// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/19/2013 11:17:13 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <string.h>
#include <stdlib.h>

#include <iostream>

void ReverseString(char* pStart, char* pEnd) 
{
    if (!pStart || !pEnd)
        return;
    pEnd--;
    while (pStart < pEnd) {
        char temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;

        pStart++;
        pEnd--;
    }
}

/**
 * Rotate the first n chars in a string to its end
 **/
 void LeftRotateString(char* pStr, int n) {
    if (!pStr) 
        return;

    size_t nLength = static_cast<int>(strlen(pStr));
    if (nLength > 0 && n > 0 && n < nLength) {
        char* pFirstStart = pStr;
        char* pFirstEnd = pStr + n;
        char* pSecondStart = pStr + n;
        char* pSecondEnd = pStr + nLength;

        // reverse the first part of the string
        ReverseString(pFirstStart, pFirstEnd);
        // reverse the second part of the string
        ReverseString(pSecondStart, pSecondEnd);
        // reverse the whole string
        ReverseString(pStr, pStr + nLength);
    }
 }

int main(int argc, char* argv[]) 
{
    if (argc < 3) {
        std::cout << "usage: " 
            << argv[0] 
            << " string n" << std::endl;
        return -1;
    }

    char* pStr = strdup(argv[1]);
    if (!pStr) 
        return -1;

    int n = atoi(argv[2]);
    LeftRotateString(pStr, n);

    std::cout << pStr << std::endl;

    return 0;
}
