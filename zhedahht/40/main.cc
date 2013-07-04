// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  06/04/2013 06:58:34 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Determing whether numbers in an array are continuous
 * Parameters: 
 *  numbers: an array, each number in the array is between 
 *           0 and max_number. 0 can be treeted as any number between
 *           1 and max_number
 *  max_number: the maximum number in the array numbers
 **/
bool IsContinuous(std::vector<int> numbers, int max_number) 
{
    if (numbers.size() == 0 || max_number <= 0) {
        return false;
    }

    // Sort the array numbers.
    std::sort(numbers.begin(), numbers.end());

    int number_of_zero = 0;
    int number_of_gap = 0;

    // How many 0s in the array ?
    std::vector<int>::iterator current_iterator = numbers.begin();
    while (current_iterator != numbers.end() && *current_iterator == 0) {
        number_of_zero++;
        current_iterator++;
    }


    // Get the total gaps between all adjacent two numbers
    std::vector<int>::iterator last_iterator = current_iterator;
    current_iterator = current_iterator + 1;
    while (current_iterator != numbers.end()) {

        // If any non-zero number appears more than once in the array, 
        // the array can't be continuous
        if (*current_iterator == *last_iterator) {
            return false;
        }

        number_of_gap += *current_iterator - *last_iterator - 1;

        last_iterator = current_iterator;
        current_iterator++;
    }

    return number_of_zero >= number_of_gap;
}

void Test1() 
{
    int array[][5] = {
        {1, 2, 5, 4, 0}, 
        {1, 1, 2, 3, 4}, 
        {10, 6, 0, 0, 0}};

    std::vector<int> numbers;

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        for (int j = 0; j < sizeof(array[0]) / sizeof(array[0][0]); j++) {
            numbers.push_back(array[i][j]);
        }

        std::cout << IsContinuous(numbers, 13) << std::endl;
        numbers.clear();
    }
}

int main(int argc, char* argv[]) 
{
    Test1();
    return 0;
}
