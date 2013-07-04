// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  06/12/2013 06:42:01 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <stdio.h>
#include <string.h>

#include <vector>

void Combination1(const char* string, std::vector<char>& result) 
{
    if (!*string) {
        if (!result.empty()) {
            std::vector<char>::iterator iter = result.begin();
            for(; iter != result.end(); iter++) {
                printf("%c", *iter);
            }
            printf("\n");
        }
    } else {
        Combination1(string + 1, result);

        result.push_back(*string);
        Combination1(string + 1, result);
        result.pop_back();
    }
}

void Combination1(const char* string) 
{
    if (!string) {
        return;
    }

    std::vector<char> result;

    Combination1(string, result);
}

void Test1() 
{
    const char* string = "abc";
    Combination1(string);
}

void Combination2(const char* string, int number, std::vector<char>& result) 
{
    if (!number) {
        std::vector<char>::iterator iter = result.begin();
        for (; iter != result.end(); iter++) {
            printf("%c", *iter);
        }
        printf("\n");
    } else if (*string) {
        Combination2(string + 1, number, result);

        result.push_back(*string);
        Combination2(string + 1, number - 1, result);
        result.pop_back();
    }
}

void Combination2(const char* string) 
{
    if (!string) {
        return;
    }

    std::vector<char> result;
    for (int i = 1; i <= strlen(string); i++) {
        Combination2(string, i, result);
    }
}

void Test2() 
{
    const char* string = "abc";
    Combination2(string);
}

int main(int argc, char* argv[]) 
{
    Test1();
    printf("\n");

    Test2();

    return 0;
}
