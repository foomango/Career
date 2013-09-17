/*
 * =====================================================================================
 *
 *       Filename:  sqrt.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/16/2013 09:35:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

const double MIN = 0.001;

double Sqrt(int n) 
{
    if (n < 0) 
        return -1;

    double i = 0;
    double j = n;
    double k;
    while (1) {
        k = (i + j) / 2;
        if (k * k > n) {
            if (k * k - n < MIN) 
                break;
            j = k;
        }
        else if (k * k < n) {
            if (n - k * k < MIN)
                break;
            i = k;
        }
        else {
            break;
        }
    }

    return k;
}

int main(int argc, char *argv[]) 
{
    int n = 1;
    cout << Sqrt(n) << endl;
    return 0;
}
