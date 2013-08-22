/*
 * =====================================================================================
 *
 *       Filename:  main2.cc
 *
 *    Description:  http://foomango.blog.163.com/blog/static/218098074201372274638214/ 
 *
 *        Version:  1.0
 *        Created:  08/22/2013 07:44:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <cstdio>

/*
 * 按行打印矩阵
 * Input: 
 *  matrix - 矩阵的基地址
 *  rows - 矩阵的行数
 *  columns - 矩阵的列数
 */
void PrintMatrixByRows(const int *matrix, int rows, int columns) 
{
    if (matrix == NULL || rows <= 0 || columns <= 0) {
        return;
    }

    for (int i = 0; i < rows * columns; ++i) {
        if (i % columns == 0) {
            printf("\n");
        }
        printf("%d\t", matrix[i]);
    }
    printf("\n");
}

/*
 * 顺时针打印矩阵
 * Input: 
 *  matrix - 矩阵的基地址
 *  rows - 矩阵的行数
 *  columns - 矩阵的列数
 */
void PrintMatrixClockwisely(const int *matrix, int rows, int columns) 
{
    if (matrix == NULL || rows <= 0 || columns <= 0) {
        return;
    }

    PrintMatrixByRows(matrix, rows, columns);

    // move current to last logical position
    const int *current = matrix - 1;
    int current_rows = rows;
    int current_columns = columns;

    while (true) {
        // print from left to right
        for (int i = 0; i < current_columns; ++i) {
            ++current;
            printf("%d\t", *current);
        }
        if (--current_rows == 0) {
            break;
        }

        // print from top to bottom
        for (int i = 0; i < current_rows; ++i) {
            current += columns;
            printf("%d\t", *current);
        }
        if (--current_columns == 0) {
            break;
        }

        // print from right to left
        for (int i = 0; i < current_columns; ++i) {
            --current;
            printf("%d\t", *current);
        } 
        if (--current_rows == 0) {
            break;
        }

        // print from bottom to top
        for (int i = 0; i < current_rows; ++i) {
            current -= columns;
            printf("%d\t", *current);
        }
        if (--current_columns == 0) {
            break;
        }
    }
    printf("\n");
}

/*
 * 单元测试PrintMatrixClockwisely函数
 */
void Test() 
{
    int rows = 0;
    int columns = 0;

    scanf("%d%d", &columns, &rows);

    int *matrix = new int[columns * rows];
    for (int i = 0; i < columns * rows; ++i) {
        scanf("%d", &matrix[i]);
    }

    PrintMatrixClockwisely(matrix, rows, columns);

    delete [] matrix;
}

int main(int argc, char *argv[]) 
{
    Test();
    return 0;
}
