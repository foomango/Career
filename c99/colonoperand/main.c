// =====================================================================================
// 
//       Filename:  main.c
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  09/15/2013 09:12:09 AM
//       Revision:  none
//       Compiler:  gcc
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <stdio.h>

int main(int argc, char *argv[]) 
{
    int n = 0;
    printf("n = 0 < 1 ? printf(\"1\\n\") : printf(\"2\\n\");\n");
    n = 0 < 1 ? printf("1\n") : printf("2\n");

    printf("n = 0 > 1 ? printf(\"1\\n\") : printf(\"2\\n\");\n");
    n = 0 > 1 ? printf("1\n") : printf("2\n");

    printf("n = 0 > 1 ? 1 < 0 ? printf(\"1\\n\") : printf(\"2\\n\") : printf(\"3\\n\");\n");
    n = 0 > 1 ? 1 > 0 ? printf("1\n") : printf("2\n") : printf("3\n");

    return 0;
}
