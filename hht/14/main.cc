/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/02/2013 09:09:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>

#include <stdlib.h>

/**
 * n integers (0, 1, ... n - 1) form a circle. Remove the mth from 
 * the circle at every time. Find the last number remaining
 * Input: n - the number of integers in the circle initially 
 *        m - remove the mth number at every time
 * Output: the last number remaining when the input is valid, 
 *         otherwise -1
 **/
int LastRemaining(int n, int m) {
    // invalid input
    if (n <= 0 || m <= 0) {
        return -1;
    }

    // if there are only one integer in the circle initially, 
    // of course the last remaining one is 0
    int lastinteger = 0;

    // find the last remaining one in the circle with n integers
    for (int i = 2; i <= n; i++) {
        lastinteger = (lastinteger + m) % i;
    }

    return lastinteger;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " n k" << std::endl;
        return -1;
    }

    std::cout << LastRemaining(atoi(argv[1]), atoi(argv[2])) << std::endl;
    return 0;
}
