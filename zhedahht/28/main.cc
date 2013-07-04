// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  06/12/2013 08:33:47 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>

/**
 * Print the permutation of a string.
 * Input: str - input string
 *        being - points to the begin of string which we want to permutate in this 
 *                recursion
 */
void Permutation(char* str, char* begin) 
{
    if (!str || !begin) {
        return;
    }

    // if begin points to the end of string, 
    // this round of permutation is finished, 
    // print the permuted string
    if (*begin == '\0') {
        std::cout << str << std::endl;  
    } else {
        // otherwise, permute string
        for (char* ch = begin; *ch != '\0'; ch++) {
            // swap ch and begin
            char temp = *ch;
            *ch = *begin;
            *begin = temp;

            Permutation(str, begin + 1);

            // restore ch and begin
            *begin = *ch;
            *ch = temp;
        }
    }
}

/**
 * Get the permutaion of a string, 
 */
void Permutation(char* str) {
    Permutation(str, str);
}

int main(int argc, char* argv[]) 
{
    char str[] = "abc";
    Permutation(str);

    return 0;
}
