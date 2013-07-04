// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/16/2013 09:02:31 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>

/**
 * Get the longest length of its all symmetrical substrings
 * Time needed is O(T^2)
 **/
int GetLongestSymmetricalLength(const char* pString) 
{
    if (!pString) {
        return 0;
    }

    int symmetricalLength = 1;

    const char* pChar = pString;
    while (*pChar != '\0') {

        // Substring with odd length
        const char* pFirst = pChar - 1;
        const char* pLast = pChar + 1;
        while (pFirst >= pString && *pLast != '\0' && *pFirst == *pLast) {
            pFirst--;
            pLast++;
        }
        int newLength = pLast - pFirst - 1;
        if (newLength > symmetricalLength) {
            symmetricalLength = newLength;
        }

        // Substring with even length
        pFirst = pChar;
        pLast = pChar + 1;
        while (pFirst >= pString && *pLast != '\0' && *pFirst == *pLast) {
            pFirst--;
            pLast++;
        }
        newLength = pLast - pFirst - 1;
        if (newLength > symmetricalLength) {
            symmetricalLength = newLength;
        }

        pChar++;
    }

    return symmetricalLength;
}

int main(int argc, char* argv[]) 
{
    const char* str1 = "google";
    const char* str2 = "sasaaaasas";

    std::cout << str1 << " : " << GetLongestSymmetricalLength(str1) << std::endl;
    std::cout << str2 << " : " << GetLongestSymmetricalLength(str2) << std::endl;

    return 0;
}
