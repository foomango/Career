// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  06/02/2013 03:53:54 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>
#include <stdexcept>

/**
 * Get hte minimum number of a roatation of a sorted array
 **/
int MinSortedRoatationCore(int* start, int* end) 
{
    if (start == end) {
        return *start;
    }

    int* mid = start + ((end - start) / 2);

    if (*mid == *start && *mid == *end) {
        int left_result = MinSortedRoatationCore(start, mid);
        int right_result = MinSortedRoatationCore(mid + 1, end);
        if (left_result < *mid && right_result < *mid) {
            throw new std::invalid_argument("Not a roatation of a sorted array");
        } else {
            return left_result < right_result ? left_result : right_result;
        }
    }

    // Not a roatation
    if (*start <= *mid && *mid <= *end) {
        return *start;
    // Min number appears in the right
    } else if (*mid >= *start && *mid >= *end && *end <= *start) {
        return MinSortedRoatationCore(mid + 1, end);
    } else if (*mid <= *start && *mid <= *end && *end <= *start) {
        return MinSortedRoatationCore(start, mid);
    } else {
        throw new std::invalid_argument("Not a roatation of a sorted array");
    }

}

int MinSortedRoatation(int* numbers, int length) 
{
    if (!numbers || length <= 0) {
        throw new std::invalid_argument("Invalid arguments");
    } else {
        return MinSortedRoatationCore(numbers, numbers + length - 1);
    }
}

void Test1() 
{
    int numbers1[] = {3, 4, 0, 1, 3};
    int numbers2[] = {2, 3, 1, 4, 7};
    int numbers3[] = {1, 0, 1, 1, 1};

    int length1 = sizeof(numbers1) / sizeof(numbers1[0]);
    int length2 = sizeof(numbers2) / sizeof(numbers2[0]);
    int length3 = sizeof(numbers3) / sizeof(numbers3[0]);

    std::cout << MinSortedRoatation(numbers1, length1) << std::endl
        << MinSortedRoatation(numbers3, length3) << std::endl
//        << MinSortedRoatation(numbers2, length2) 
    << std::endl;
}

int main(int argc, char* argv[]) 
{
    Test1();
    return 0;
}
