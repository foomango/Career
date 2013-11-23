/*
 * =====================================================================================
 *
 *       Filename:  1.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/25/2013 01:58:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

#define MAX ((1 << 31) - 2)
typedef struct choice {
    int smallest;
    int number;
} choice_t;

int Cal(int money, int m, choice_t *opt, vector<int> &price) 
{
    (opt + m)->smallest = 0;
    (opt + m)->number = 0;
    for (int i = 1; i <= money; ++i) {
        (opt + i * (m + 1) + m)->smallest = MAX;
        (opt + i * (m + 1) + m)->number = 0;
    }

    for (int j = m - 1; j >= 0; --j) {
        for (int i = 0; i <= money; ++i) {
            (opt + i * (m + 1) + j)->smallest = MAX;
            for (int k = 0; k * price[j] <= i; ++k) {
                int x = (opt + (i - k * price[j]) * (m + 1) + j + 1)->smallest;
                if (x != MAX) {
                    x += k;
                    if (x < (opt + i * (m + 1) + j)->smallest) {
                        (opt + i * (m + 1) + j)->smallest = x;
                        (opt + i * (m + 1) + j)->number = k;
                    }
                }
            }
        }
    }

    return (opt + money * (m + 1))->smallest;
}

vector < int > caculate(vector < int > a, int b) {
    vector <int> result;

    int m = a.size();
    int money = b;
    vector<int> &price = a;
    choice_t *opt = new choice_t[(m + 1) * (money + 1)];

    int smallest = Cal(money, m, opt, price);

    if (smallest == MAX) {
        return result;
    }   
    else {
        for (int i = 0; i < m; ++i) {
            result.push_back((opt + money * (m + 1) + i) -> number);
            money -= ((opt + money * (m + 1) + i) -> number) * price[i];
        }   
    }

    delete[] opt;
}

int main(int argc, char *argv) 
{
    //const int m = 4;
    //int price[m] = {1, 3, 4, 5};
    //int money = 7;

    const int m = 3;
    vector<int> price; // [m] = {3, 4, 5};
    price.push_back(1);
    price.push_back(3);
    price.push_back(4);
    price.push_back(5);

    int money = 7;

    choice_t *opt = new choice_t[(m + 1) * (money + 1)];

    vector<int> result = caculate(price, money);

    /*int smallest = Cal(money, m, opt, price);

    if (smallest == MAX) {
        cout << "0";
    }
    else {
        for (int i = 0; i < m; ++i) {
            cout << (opt + money * (m + 1) + i) -> number << " ";
            money -= ((opt + money * (m + 1) + i) -> number) * price[i];
        }
    }
    cout << endl;

    cout << smallest << endl;*/

    delete[] opt;

    return 0;
}
