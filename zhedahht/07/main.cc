// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/21/2013 07:28:14 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>

#include <string.h>

/**
 * Reverse a string between two pointers
 * Input:   pBegin  - the begin pointer in a string
 *          pEnd    - the end pointer in a string
 **/
void Reverse(char* pBegin, char* pEnd) 
{
    if (!pBegin || !pEnd) 
        return;

    while (pBegin < pEnd) {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;
        pBegin++;
        pEnd--;
    }
}

/**
 * Reverse the word order in a sentence, but maintain the character
 * Input: pData - the centence to be reversed
 **/
char* ReverseSentence(char* pData) 
{
    if (!pData) 
        return NULL;
    
    int nLength = strlen(pData);
    char* pBegin = pData;
    char* pEnd = pData + nLength - 1;

    // reverse the whole centence
    Reverse(pBegin, pEnd);

    // reverse every word in the sentence
    pEnd = pBegin;
    while (*pBegin != '\0') {
        if (*pBegin == ' ') {
            pBegin++;
            pEnd++;
            continue;
        }

        while (*pEnd != ' ' && *pEnd != '\0') {
            pEnd++;
        }

        // a word is between with pBegin and pEnd, reverse it
        Reverse(pBegin, --pEnd);
        pBegin = ++pEnd;

    }

    return pData;
}

int main(int argc, char* argv[]) 
{
    std::string str;
    std::getline(std::cin, str);

    char * pStr = strdup(str.c_str());
    if (!pStr) 
        return -1;

    std::cout << ReverseSentence(pStr) << std::endl;

    return 0;
}
