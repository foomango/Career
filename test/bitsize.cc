// =====================================================================================
// 
//       Filename:  bitsize.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  06/22/2013 10:07:00 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <stdio.h>

struct s1 
{
    int i: 8;
    int j: 4;
    int a: 3;
    double b;
};

struct s2 
{
    int i: 8;
    int j: 4;
    double b;
    int a;
};

struct a 
{
    double b;
    //short a;
};

int main(int argc, char* argv[]) 
{
    struct s2 s22;
    printf("sizeof(s1)= %lu\n", sizeof(s1));
    printf("sizeof(s2)= %lu\n", sizeof(s2));
    printf("sizeof(int)= %lu\n", sizeof(int));
    printf("sizeof(a)= %lu\n", sizeof(a));
    return 0;
}
