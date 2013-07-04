// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/20/2013 08:47:44 PM
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
 * Find the first char which appears only once in a string
 * Input:  pString - the sring
 * Output: the first not repeating char if the string has, otherwise 0
 **/
char FirstNotRepeatingChar(const char* pString) 
{
    // invalid iput
    if (!pString) 
        return 0;

    // create a hash table
    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    memset(hashTable, 0, sizeof(hashTable));

    // get how many times each char appears in the sting
    const char* pHashKey = pString;
    while ((*pHashKey) != '\0') {
        hashTable[*pHashKey++]++;
    }

    // find first char which appears only once in a string
    for (pHashKey = pString; *pHashKey != '\0'; pHashKey++) {
        if (hashTable[*pHashKey] == 1) 
            return *pHashKey;
    }

    return 0;
}

int main(int argc, char* argv[]) 
{
    if (argc < 2) {
        return -1;
    }

    const char* str = argv[1];
    std::cout << FirstNotRepeatingChar(str) << std::endl;

    return 0;
}
