// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  06/02/2013 09:42:27 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>

void PrintMatrixClockwisely(int** numbers, int columns, int rows) 
{
    if (!numbers || columns <= 0 || rows <= 0) {
        return;
    }

    // move current to last logical position
    int* current = (int *)numbers - 1;
    int currentColumns = columns;
    int currentRows = rows;

    while (true) {
        // print left to right
        for (int left2RightX = 0; left2RightX < currentColumns; left2RightX++) {
            current++;
            std::cout << *current << "\t";
        }

        if (--currentRows <= 0) {
            break;
        }

        // print top to bottom
        for (int top2Bottom = 0; top2Bottom < currentRows; top2Bottom++) {
            current += columns;
            std::cout << *current << "\t";
        }

        if (--currentColumns <= 0) {
            break;
        }

        // print right to left
        for (int right2Left = 0; right2Left < currentColumns; right2Left++) {
            current--;
            std::cout << *current << "\t";
        }

        if (--currentRows <= 0) {
            break;
        }

        // print bottom to top
        for (int bottom2Top = 0; bottom2Top < currentRows; bottom2Top++) {
            current -= columns;
            std::cout << *current << "\t";
        }

        if (--currentColumns <= 0) {
            break;
        }
    }
}

void Test1() 
{
    int columns = 0;
    int rows = 0;

    std::cin >> columns >> rows;

    int* numbers = new int[columns * rows];
    int* current = numbers;
    int* end = numbers + (columns * rows);
    for (; current < end; current++) {
        std::cin >> *current;
    }
    PrintMatrixClockwisely((int**)numbers, columns, rows);
    std::cout << std::endl;
}

int main(int argc, char* argv[]) 
{
    Test1();
    return 0;
}
