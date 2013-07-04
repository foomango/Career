/*
 * =====================================================================================
 *
 *       Filename:  testZeroVector.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/27/2013 09:39:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>

int main(int argc, char *argv[]) {
    int vec[256] = {1, 2};
    for (int i = 0; i < 256; i++) {
        std::cout << vec[i] << " ";
        if (vec[i] != 0) {
            std::cout << "failed" << std::endl;
        }
    }
}
