// =====================================================================================
// 
//       Filename:  agesort.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/24/2013 09:28:28 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>

#include <string.h>
#include <assert.h>

typedef struct {
    int numbers;
    int index;
} HelperIndex_t;

void AgeSort(char* numbers, int length) 
{
    const int maxAge = 100;
    HelperIndex_t helper[maxAge]; 
    memset(helper, 0, sizeof(helper));

    // calculate numbers of earch age
    for (int i = 0; i < length; i++) {
        helper[numbers[i]].numbers++;
    }

    // calculate curbase of earch age
    for (int j = 1; j < maxAge; j++) {
        helper[j].index = helper[j - 1].index + helper[j - 1].numbers;
        helper[j - 1].numbers = helper[j].index;
    }
    helper[maxAge - 1].numbers = length;

    // sort
    int index = 0;
    while (1) {
        while (helper[index].index >= helper[index].numbers) {
            if (++index > maxAge) {
                return;
            }
        }
        int& currentIndex = helper[index].index;
        int currentAge = numbers[currentIndex];
        int temp = 0;
        while (index != currentAge) {
            //assert(helper[currentAge].index <= helper[currentAge].numbers);
            temp = numbers[helper[currentAge].index];
            numbers[helper[currentAge].index++] = currentAge;
            currentAge = temp;
        }
        numbers[currentIndex++] = currentAge;
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

    AgeSort(numbers, length);

    for (int j = 0; j < length; j++) {
        std::cout << (int)numbers[j] << std::endl;
    }

    return 0;
}
