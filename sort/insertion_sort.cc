/*
 * =====================================================================================
 *
 *       Filename:  insertion_sort.cc
 *
 *    Description:  insertion sort
 *
 *        Version:  1.0
 *        Created:  04/10/2013 10:21:56 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>

#include <stdio.h>
#include <stdlib.h>

#include<time.h>

void print_array(int array[], int len);

void insertion_sort(int array[], int first, int last) {
    if (array == NULL || first < 0) {
        return;
    }

    for (int i = first + 1; i <= last; i++) {
        int temp = array[i];
        int j = 0;
        for (j = i - 1; j >= first && array[j] > temp; j--) {
            array[j + 1] = array[j];
        }
        array[j + 1] = temp;
    }
}

void generate_array(int array[], int len) {
    int seed = time(NULL);
    srand(seed);
    for (int i = 0; i < len; i++) {
        array[i] = random() % (10 * len);
    }
}

void print_array(int array[], int len) {
    for (int i = 0; i < len; i++) {
        if (i % 10 == 0) {
            printf("\n");
        }
        printf("\t%d", array[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    const int len = 20;
    int array[len];
    generate_array(array, len);
    printf("before sort:\n");
    print_array(array, len);
    printf("after sort:\n");
    insertion_sort(array, 0, len - 1);
    print_array(array, len);

    return 0;
}
