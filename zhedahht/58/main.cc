/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  Eight queen
 *
 *        Version:  1.0
 *        Created:  07/05/2013 07:34:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int g_total = 0;

void PrintQueen(int column_index[], int length) 
{
    assert(column_index != NULL);
    assert(length > 0);

    printf("Solution %d\n", g_total);

    for (int i = 0; i < length; i++) {
        printf("%d\t", column_index[i]);
    }

    printf("\n");
}

bool Check(int column_index[], int length) 
{
    assert(column_index != NULL);
    assert(length > 0);

    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (abs(column_index[i] - column_index[j]) == abs(i - j)) {
//                printf("[%d, %d] abs:%d\n", column_index[i], column_index[j], abs(column_index[i] - column_index[j]));
                return false;
            }
        }
    }

    return true;
}

bool Check2(int column_index[], int index)
{
    assert(column_index != NULL);
    assert(index >= 0);

    for (int i = 0; i < index; i++) {
        int diff_column = column_index[i] - column_index[index];
        int diff_row = i - index;
        if (diff_column == diff_row || diff_column == -diff_row) {
            return false;
        }
    }

    return true;
}

void Permutation(int column_index[], int length, int index) {
    assert(column_index != NULL);
    assert(length > 0);
    assert(index >= 0);
    assert(index <= length);

    if (index == length) {
        if (Check2(column_index, index - 1)) {
            g_total++;
            PrintQueen(column_index, length);
        }
        return;
    }

    if (index > 0 && !Check2(column_index, index - 1)) {
        return;
    }

    for (int i = index; i < length; i++) {
        int temp = column_index[i];
        column_index[i] = column_index[index];
        column_index[index] = temp;

        Permutation(column_index, length, index + 1);

        temp = column_index[index];
        column_index[index] = column_index[i];
        column_index[i] = temp;
    }
}

void EightQueens() 
{
    const int queens = 13;
    int column_index[queens];
    for (int i = 0; i < queens; i++) {
        column_index[i] = i;
    }

    Permutation(column_index, queens, 0);
}

int main(int argc, char* argv[]) 
{
    EightQueens();

    return 0;
}
