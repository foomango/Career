/*
 * =====================================================================================
 *
 *       Filename:  maxheap.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/11/2013 02:54:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv) 
{
    size_t size = (size_t)7 * 1024 * 1024 * 1024;
    char *p = malloc(size);
    int size_g = (int)(size / 1024 / 1024 / 1024);
    if (p) {
        printf("malloc %fG success.\n", (float)size_g);
    } else {
        printf("malloc %fG failed.\n", (float)size_g);
    }
    return 0;
}
