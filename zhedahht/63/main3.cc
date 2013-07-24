/*
 * =====================================================================================
 *
 *       Filename:  main3.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/24/2013 08:06:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <vector>
#include <cstdio>

using std::vector;
using std::swap;

inline int FirstBitOf1(int number) 
{
    return number & -number;
}

void GetTwoUnique(vector<int>::iterator begin, vector<int>::iterator end, vector<int>& unique) 
{
    // Get xor result
    int xor_result = 0;
    for (vector<int>::iterator iter = begin; 
            iter != end; ++iter) {
        xor_result ^= *iter;
    }

    // Get flag 
    int flag = FirstBitOf1(xor_result);

    // Get the two uniques
    int first_unique = 0;
    int second_unique = 0;
    for (vector<int>::iterator iter = begin; 
            iter != end; ++iter) {
        if ((*iter & flag) == 0) {
            first_unique ^= *iter;
        } 
        else {
            second_unique ^= *iter;
        }
    }
    unique.push_back(first_unique);
    unique.push_back(second_unique);
}

void GetTreeUnique(vector<int>& numbers, vector<int>& unique) 
{
    if (numbers.size() < 3 || numbers.size() % 2 == 0) {
        return;
    }

    // Get xor result
    int xor_result = 0;
    for (vector<int>::iterator iter = numbers.begin();
            iter != numbers.end(); ++iter) {
        xor_result ^= *iter;
    }

    // Get flag
    int flag = 0;
    for (vector<int>::iterator iter = numbers.begin(); 
            iter != numbers.end(); ++iter) {
        flag ^= FirstBitOf1(*iter ^ xor_result);
    }

    // Get first unique
    int first_unique = 0;
    for (vector<int>::iterator iter = numbers.begin(); 
            iter != numbers.end(); ++iter) {
        if (((*iter ^ xor_result) & flag) == 0) {
            first_unique ^= *iter;
        }
    }
    unique.push_back(first_unique);

    // Swap first unique and the last one
    for (vector<int>::iterator iter = numbers.begin(); 
            iter != numbers.end(); ++iter) {
        if (*iter == first_unique) {
            swap(*iter, *(numbers.end() - 1));
            break;
        }
    }

    // Get the other two uniques
    GetTwoUnique(numbers.begin(), numbers.end() - 1, unique);
}

int main(int argc, char* argv[]) 
{
    int number;
    vector<int> numbers;
    while (scanf("%d", &number) != EOF) {
        numbers.push_back(number);
    }

    vector<int> unique;
    GetTreeUnique(numbers, unique);

    for (vector<int>::iterator iter = unique.begin(); 
            iter != unique.end(); ++iter) {
        printf("%d\t", *iter);
    }
    printf("\n");

    return 0;
}
