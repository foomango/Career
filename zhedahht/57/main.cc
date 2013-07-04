// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/28/2013 08:59:41 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>
#include <stdexcept>

#include <string.h>

void SortAges(char ages[], int length) 
{
    if (ages == NULL || length <= 0) {
        return;
    }

    const int oldestAge = 99;
    int timesOfAge[oldestAge + 1];

    memset(timesOfAge, 0, sizeof(timesOfAge));

    for (int i = 0; i < length; i++) {
        if (ages[i] < 0 || ages[i] > oldestAge) {
            throw new std::runtime_error("age out of range.");
        }
        timesOfAge[i]++;
    }

    int index = 0;
    for (int i = 0; i < oldestAge; i++) {
        for (int j = 0; j < timesOfAge[i]; j++) {
            ages[index++] = i;
        }
    }
}

int main(int argc, char* argv[]) 
{
    const int length = 100000;
    char *numbers = new char[length];

    if (!numbers) {
        return -1; 
    }   

    for (int i = 0; i < length; i++) {
        int temp;
        std::cin >> temp;
        numbers[i] = temp;
    }   

    SortAges(numbers, length);

    for (int j = 0; j < length; j++) {
        std::cout << (int)numbers[j] << std::endl;
    }   

    return 0;
}
