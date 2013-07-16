/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/15/2013 06:53:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <cstring>
#include <cstdio>

// Maximum int number has 10 digits in decimal system
const int g_max_number_length = 10;

// String buffers to combine two numbers
char* g_str_combine1 = new char[g_max_number_length * 2 + 1];
char* g_str_combine2 = new char[g_max_number_length * 2 + 1];

/*
 * Compare two numbers in str_number1 and str_number2
 * if [str_number1][str_number2] > [str_number2][str_number1], 
 * return value > 0
 * if [str_number1][str_number2] = [str_number2][str_number1], 
 * return value = 0
 * if [str_number1][str_number2] < [str_number2][str_number1], 
 * return value < 0
 */
int compare(const void* str_number1, const void* str_number2) 
{
    char g_str_combine1[g_max_number_length * 2 + 1];
    char g_str_combine2[g_max_number_length * 2 + 1];

    // [str_number1][str_number2]
    strcpy(g_str_combine1, *(const char**)str_number1);
    strcat(g_str_combine1, *(const char**)str_number2);

    // [str_number2][str_number1]
    strcpy(g_str_combine2, *(const char**)str_number2);
    strcat(g_str_combine2, *(const char**)str_number1);

    return strcmp(g_str_combine1, g_str_combine2);
}

/*
 *  Given an array, print the minimum array
 */
void PrintMinNumber(int* numbers, int length) 
{
    if (numbers == NULL || length <= 0) {
        return;
    }

    // Convert all numbers as strings
    char** str_numbers = (char**)(new char*[length]);
    for (int i = 0; i < length; i++) {
        str_numbers[i] = new char[g_max_number_length + 1];
        sprintf(str_numbers[i], "%d", numbers[i]);
    }

    // Sort all strings according to algrithm in function compare
    qsort(str_numbers, length, sizeof(char*), compare);

    for (int i = 0; i < length; i++) {
        printf("%s", str_numbers[i]);
    }
    printf("\n");

    for (int i = 0; i < length; i++) {
        delete[] str_numbers[i];
    }
    delete[] str_numbers;
}

int main(int argc, char* argv[]) 
{
    int numbers[] = {32, 324, 321, 55, 123};
    PrintMinNumber(numbers, sizeof(numbers) / sizeof(numbers[0]));

    return 0;
}
