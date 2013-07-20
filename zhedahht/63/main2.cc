// =====================================================================================
// 
//       Filename:  main2.cc
// 
//    Description:  http://foomango.blog.163.com/blog/static/218098074201362010362496/
// 
//        Version:  1.0
//        Created:  07/20/2013 10:34:43 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <cstdio>
#include <cstdlib>
#include <vector>

using std::vector;

inline int FirstBitOf1(int number) 
{
    return number & -number;
}

void GetTwoUnique(vector<int>::iterator begin, 
        vector<int>::iterator end, 
        vector<int>& unique) 
{
    int xor_result = 0;
    vector<int>::iterator iter = begin;
    while (iter != end) {
        xor_result ^= *iter;
        ++iter;
    }

    int flag = FirstBitOf1(xor_result);
    int first_unique = 0;
    int second_unique = 0;
    iter = begin;
    while (iter != end) {
        if ((flag & *iter) != 0) {
            first_unique ^= *iter;
        }
        else {
            second_unique ^= *iter;
        }
        ++iter;
    }

    unique.push_back(first_unique);
    unique.push_back(second_unique);
}

void GetThreeUnique(vector<int>& numbers, vector<int>& unique) 
{
    if (numbers.size() < 3 || numbers.size() % 2 != 1) {
        return;
    }

    // Calculate xor of numbers
    int xor_result = 0;
    for (vector<int>::iterator iter = numbers.begin();
            iter != numbers.end(); ++iter) {
        xor_result ^= *iter;
    }

    // Calculate flag
    int flag = 0;
    for (vector<int>::iterator iter = numbers.begin(); 
            iter != numbers.end(); ++iter) {
        flag ^= FirstBitOf1(xor_result ^ *iter);
    }
    flag = FirstBitOf1(flag);

    // Get the first unique number
    int first_unique = 0;
    for (vector<int>::iterator iter = numbers.begin(); 
            iter != numbers.end(); ++iter) {
        if ((flag & (xor_result ^ *iter)) == 0) {
            first_unique ^= *iter;
        }
    }
    unique.push_back(first_unique);

    // Swap first_unique and the last number in numbers
    for (vector<int>::iterator iter = numbers.begin(); 
            iter != numbers.end(); ++iter) {
        if (*iter == first_unique) {
            std::swap(*iter, *(numbers.end() - 1));
            break;
        }
    }

    // Get the last two unique numbers
    GetTwoUnique(numbers.begin(), numbers.end() - 1, unique);

}

int main(int argc, char* argv[]) 
{
    int length = 0;
    scanf("%d", &length);
    if (length < 1) {
        exit(-1);
    }

    vector<int> numbers;
    vector<int> unique;
    int temp = 0;
    while (scanf("%d", &temp) != EOF) {
        numbers.push_back(temp);
    }

    GetThreeUnique(numbers, unique);
    
    for (vector<int>::iterator iter = unique.begin(); 
            iter != unique.end();
            ++iter) {
        printf("%d\t", *iter);
    }

    return 0;
}
