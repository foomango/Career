// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/21/2013 09:17:45 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>
#include <vector>

inline int lastBitOf1(int num) 
{
    return num & -num;
}

void getTwoUnique(
        std::vector<int>::iterator begin, 
        std::vector<int>::iterator end, 
        std::vector<int>& unique) 
{
    int xorResult = 0;
    for (std::vector<int>::iterator iter = begin; iter != end; iter++) {
        xorResult ^= *iter;
    }

    int diff = lastBitOf1(xorResult);
    int first = 0;
    int last = 0;
    for (std::vector<int>::iterator iter = begin; iter != end; iter++) {
        if (diff & *iter) {
            first ^= *iter;
        } 
        else {
            last ^= *iter;
        }
    }

    unique.push_back(first);
    unique.push_back(last);
}

void getThreeUnique(std::vector<int>& numbers, std::vector<int>& unique) 
{
    int xorResult = 0;
    for (std::vector<int>::iterator iter = numbers.begin(); 
            iter != numbers.end(); iter++) {
        xorResult ^= *iter;
    }

    int flag = 0;
    for (std::vector<int>::iterator iter = numbers.begin(); 
            iter != numbers.end(); iter++) {
        flag ^= lastBitOf1(xorResult ^ *iter);
    }
    flag = lastBitOf1(flag);

    int first = 0;
    for (std::vector<int>::iterator iter = numbers.begin(); 
            iter != numbers.end(); iter++) {
        if (!(flag & (xorResult ^ *iter))) {
            first ^= *iter;
        }
    }

    for (std::vector<int>::iterator iter = numbers.begin(); 
            iter != numbers.end(); iter++) {
        if (*iter == first) {
            std::swap(*iter, *(numbers.end() - 1));
        }
    }

    unique.push_back(first);

    getTwoUnique(numbers.begin(), numbers.end() - 1, unique);
}

int main(int argc, char* argv[]) {

    int length;
    std::cin >> length;
    std::vector<int> numbers;
    
    for (int i = 0; i < length; i++) {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }

    std::vector<int> unique;
    getThreeUnique(numbers, unique);

    for (std::vector<int>::iterator iter = unique.begin(); 
            iter != unique.end(); iter++) {
        std::cout << *iter << " " << std::endl;
    }

    std::cout << std::endl;
}
