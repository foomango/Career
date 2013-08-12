/*
 * =====================================================================================
 *
 *       Filename:  main4.cc
 *
 *    Description: http://foomango.blog.163.com/blog/static/218098074201362884935937/ 
 *
 *        Version:  1.0
 *        Created:  08/12/2013 09:15:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>

using std::cout;
using std::endl;

/*
 * Number of solutions of eight queens
 */
int g_number = 0;

/*
 * 检查当前序列是否满足八皇后条件
 * Input:
 *  column_index - 列索引数组，保存每列中皇后的行号
 *  end - The last queen's index
 */
bool Check(const int* column_index, int end) 
{
    for (int i = 0; i < end; ++i) {
        if (column_index[i] - column_index[end] == i - end || 
                column_index[i] - column_index[end] == end - i) {
            return false;
        }
    }

    return true;
}

/*
 * Print a queen
 * Input:
 *  column_index - 列索引数组，保存每列中皇后的行号
 *  length - Lenght of column_index
 */
void PrintQueen(const int* column_index, int length) 
{
    cout << "Solution " << g_number << endl;
    for (int i = 0; i < length; ++i) {
        cout << column_index[i] << "\t";
    }
    cout << endl;
}

/*
 * Permutation of eight queens
 * Input: 
 *  column_index - 列索引数组，保存数组中每列皇后的行号
 *  length - Length of column_index
 *  index - Index of current queen
 */
void PermutationOfEightQueens(int* column_index, int length, int index) 
{
    // 利用八皇后条件进行剪枝，如果前面的皇后序列不符合条件，则后面的所有皇后都不符合条件
    if (!Check(column_index, index - 1)) {
        return;
    }

    // 如果所有皇后都排列好，则成功的到一个解
    if (index == length) {
        ++g_number;
        PrintQueen(column_index, length);
        return;
    }

    // 以当前index为起点进行全排列
    for (int i = index; i < length; ++i) {
        int temp = column_index[i];
        column_index[i] = column_index[index];
        column_index[index] = temp;

        PermutationOfEightQueens(column_index, length, index + 1);

        temp = column_index[i];
        column_index[i] = column_index[index];
        column_index[index] = temp;
    }
}

/*
 * Print all solutions for eight queens
 */
void EightQueens() 
{
    const int queens = 8;
    int column_index[queens];
    for (int i = 0; i < queens; ++i) 
    {
        column_index[i] = i;
    }

    PermutationOfEightQueens(column_index, queens, 0);
}

int main(int argc, char* argv[]) 
{
    EightQueens();
    return 0;
}
