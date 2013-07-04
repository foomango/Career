// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/17/2013 08:50:55 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>
#include <string>

#include <string.h>

/**
 * Delete all characters in pStrDelete from pStrSource
 **/
void DeleteChars(char* pStrSource, const char* pStrDelete) 
{
    if (!pStrSource || !pStrDelete) {
        return;
    }

    // Initialize an array, the index in this array is ASCII value.
    // All entries in the array, whoes index is ASCII value of a 
    // character in the pStrDelete, will be set as 1.
    // Otherwise, they will be set as 0.
    const unsigned int nTableSize = 256;
    int hashTable[nTableSize];
    memset(hashTable, 0, sizeof(hashTable));

    const char* pTemp = pStrDelete;
    while (*pTemp != '\0') {
        hashTable[*pTemp] = 1;
        pTemp++;
    }

    char* pSlow = pStrSource;
    char* pFast = pStrSource;
    while ('\0' != *pFast) {
        // If the character is not in pStrDelete, move both pFast and pSlow
        // forward, and copy pFast to pSlow.
        // Otherwise, move only pStrFast forward, and the character pointed 
        // by pFirst is deleted.
        if (1 != hashTable[*pFast]) {
            *pSlow = *pFast;
            pSlow++;
        }

        pFast++;
    }

    *pSlow = '\0';

}

int main(int argc, char* argv[]) 
{
    if (argc < 3) {
        return -1;
    }

    char *pStrSource, *pStrDelete;

    pStrSource = strdup(argv[1]);
    if (!pStrSource) 
        return -1;

    pStrDelete = argv[2];

    DeleteChars(pStrSource, pStrDelete);

    std::cout << pStrSource << std::endl;

    return 0;
}
