/*
 * =====================================================================================
 *
 *       Filename:  main5.cc
 *
 *    Description:  http://foomango.blog.163.com/blog/static/218098074201362884935937/
 *
 *        Version:  1.0
 *        Created:  08/13/2013 07:42:00 PM
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
 * Number of valid queens
 */
int g_queens_number = 0;

/*
 * Check valid eight queens
 * Input: 
 *  row_numbers - Row numbers of each possible queens, indexed by colomn
 *  index - Last column index
 * Output:
 *  If row_numbers end by index is valid, return true, otherwise false
 */
bool Check(const int* row_numbers, int index) 
{
    for (int i = 0; i < index; ++i) {
        if (row_numbers[i] - row_numbers[index] == i - index || 
                row_numbers[i] - row_numbers[index] == index - i) {
            return false;
        }
    }
    return true;
}

/*
 * Print a queen
 * Input: 
 *  row_numbers - Row numbers of a valid queen, index by column
 *  int length - Length of row_numbers
 */
void PrintQueen(const int* row_numbers, int length) 
{
    cout << "Solution " << g_queens_number << endl;
    for (int i = 0; i < length; ++i) {
        cout << row_numbers[i] << "\t";
    }
    cout << endl;
}

/*
 * Permutaion of all valid eight queens
 * Input:
 *  row_numbers - Row numbers of each possible queens, indexed by column
 *  length - Length of row_numbers
 *  index - Column index
 */
void PermutationOfEightQueens(int* row_numbers, int length, int index) 
{
    if (!Check(row_numbers, index - 1)) {
        return;
    }

    if (length == index) {
        ++g_queens_number;
        PrintQueen(row_numbers, length);
        return;
    }

    for (int i = index; i < length; ++i) {
        int temp = row_numbers[i];
        row_numbers[i] = row_numbers[index];
        row_numbers[index] = temp;
        PermutationOfEightQueens(row_numbers, length, index + 1);

        temp = row_numbers[i];
        row_numbers[i] = row_numbers[index];
        row_numbers[index] = temp;
    }
}

/*
 * Print all eight queens
 */
void EightQueens() 
{
    const int queens = 8;
    int row_numbers[queens];
    for (int i = 0; i < queens; ++i) {
        row_numbers[i] = i;
    }

    PermutationOfEightQueens(row_numbers, queens, 0);
}

int main(int argc, char* argv[]) 
{
    EightQueens();
    return 0;
}
