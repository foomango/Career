// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/20/2013 08:04:25 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>
#include <limits>

typedef enum Status {kValid = 0, kInvalid} Status_t;
Status_t g_Status = kValid;

/**
 * Convert a string into an integer
 **/
int Str2Int(const char* str) 
{
    g_Status = kInvalid;
    long long num = 0;

    if (!str) {
        return 0;
    }

    const char* digit = str;
    
    // the first char in the string maybe '+' or '-'
    bool minus = false;
    if (*digit == '+') {
        digit++;
    } 
    else if (minus == '-') {
        digit++;
        minus = true;
    }

    // the remaining chars in the string
    while (*digit != '\0') {
        if (*digit >= '0' && *digit <= '9') {
            num = (num * 10) + (*digit - '0');

            // overflow
            if (num > std::numeric_limits<int>::max()) {
                num = 0;
                break;
            }

            digit++;
        } 
        // if the char is not a digit, invalid input
        else {
            num = 0;
            break;
        }
    }

    if (*digit == '\0') {
        g_Status = kValid;
        if (minus) {
            num = 0 - num;
        }
    }

    return static_cast<int>(num);

}

int main(int argc, char* argv[]) {
    if (argc < 2) 
        return -1;

    const char* str = argv[1];
    int n = Str2Int(str);
    if (g_Status == kInvalid) 
        return -1;

    std::cout << n << std::endl;
    //std::cout << std::numeric_limits<int>::max() + 1 << std::endl;

    return 0;
}

