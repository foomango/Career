// =====================================================================================
// 
//       Filename:  random.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  05/24/2013 09:35:51 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  WangFengwei (mn), foomango@gmail.com
//        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
// 
// =====================================================================================

#include <iostream>

#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[]) 
{
    int round = 1;
    int mod = -1;
    int seed = time(NULL);

    if (argc > 4) {
        round = atoi(argv[1]);
        mod = atoi(argv[2]);
        seed = atoi(argv[3]);
    } else {
        switch (argc) {
            case 4:
                seed = atoi(argv[3]);
            case 3:
                mod = atoi(argv[2]);
            case 2:
                round = atoi(argv[1]);
            default:
                break;
        }
    }

    for (int i = 0; i < round; i++) {
        int randNum = rand() % mod;
        std::cout << randNum << std::endl;
    }

    return 0;
}
