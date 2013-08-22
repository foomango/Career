/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/14/2013 04:46:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <cstdio>

 struct bit_field {
    unsigned int a:15;
    unsigned int x:1;
    unsigned int b:16;
    unsigned int c:16;
    unsigned int d:16;
 };
 typedef struct bit_field bit_field_t;

 struct CS {
    unsigned short seg_idx:13;
    unsigned short ti:1;
    unsigned short rpl:2;
 };
typedef struct CS CS_t;

 int main(int argc, char* argv[]) 
 {
    bit_field_t bf;
    bf.a = 1;
    bf.x = 1;
    bf.b = 2;
    bf.c = 3;
    bf.d = 4;

    CS_t cs;
    cs.seg_idx = 0;
    cs.ti = 0;
    cs.rpl = 1;

    unsigned char* p = reinterpret_cast<unsigned char*>(&bf);
    for (int i = 0; i < sizeof(bf); ++i) {
        printf("%d\t", p[i]);
    }

    printf("\nsizeof unsigned int:%d", sizeof(unsigned int));
    printf("\n");

    p = reinterpret_cast<unsigned char*>(&cs);
    printf("cs:\n");
    for (int i = 0; i < sizeof(cs); ++i) {
        printf("%x\t", p[i]);
    }
    printf("\n");

    return 0;
 }
