/*
 * =====================================================================================
 *
 *       Filename:  main3.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/12/2013 08:01:02 PM
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

// 可行解的总个数
int g_number = 0;

/*
 * Input: 
 *  column_index - 以列号为索引的数组，保存每列中皇后的行号
 *  index - 待加入的索引
 * Output:
 *  如果待加入的数字不满足八皇后的条件，返回false，否则返回true
 */
bool Check(const int* column_index, int index) 
{
    // 由于前面的数字都满足八皇后的条件，所以只需要检查当前加入
    // 的皇后是否与前面的皇后兼容即可
    for (int i = 0; i < index; ++i) {
        if (column_index[i] - column_index[index] == i - index || 
                column_index[i] - column_index[index] == index - i) {
            return false;
        }
    }

    return true;
}

/*
 * 打印当前解
 * Input: 
 *  column_index - 以列号为索引的数组，保存每列中皇后的行号
 *  length - 数组的长度
 */
void PrintQueens(const int* column_index, int length) 
{
    cout << "Solution " << g_number << endl;
    for (int i = 0; i < length; ++i) {
        cout << column_index[i] << "\t";
    }
    cout << endl;
}

/*
 * Input:
 *  column_index - 以列号为索引的数组，保存每列中皇后的行号
 *  length - column_index的长度
 *  index - 待处理的索引
 */
void Permutation(int* column_index, int length, int index) 
{
    // 利用条件进行剪枝
    if (!Check(column_index, index - 1)) {
        return;
    }

    if (index == length) {
        ++g_number;
        PrintQueens(column_index, length);
        return;
    }

    for (int i = index; i < length; ++i) {
        int temp = column_index[i];
        column_index[i] = column_index[index];
        column_index[index] = temp;

        Permutation(column_index, length, index + 1);

        temp = column_index[i];
        column_index[i] = column_index[index];
        column_index[index] = temp;
    }
}

/*
 * 打印八皇后的所有解
 */
void EightQueens() 
{
    const int queens = 8;
    int column_index[queens];
    for (int i = 0; i < queens; ++i) {
        column_index[i] = i;
    }

    Permutation(column_index, queens, 0);
}

int main(int argc, char* argv[]) 
{
    EightQueens();
    return 0;
}
