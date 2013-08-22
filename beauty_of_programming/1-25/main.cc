/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  Problem 1.16 of Beauty Of Programming
 *
 *        Version:  1.0
 *        Created:  08/13/2013 08:34:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostringstream;

const double threshold = 1E-6;
const int cards_number = 4;
const int result_value = 24;
double number[cards_number];
string result[cards_number];

bool PointsGame(int n) 
{
    if (n == 1) {
        if (fabs(number[0] - 24) < threshold) {
            cout << result[0] << endl;
            return true;
        }
        else {
            return false;
        }
    } 

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double a, b;
            string expa, expb;

            a = number[i];
            b = number[j];
            number[j] = number[n - 1];

            expa = result[i];
            expb = result[j];
            result[j] = result[n - 1];

            result[i] = "(" + expa + "+" + expb + ")";
            number[i] = a + b;
            if (PointsGame(n - 1)) {
                return true;
            }

            result[i] = "(" + expa + "-" + expb + ")";
            number[i] = a - b;
            if (PointsGame(n - 1)) {
                return true;
            }

            result[i] = "(" + expb + "-" + expa + ")";
            number[i] = b -a;
            if (PointsGame(n - 1)) {
                return true;
            }

            result[i] = "(" + expa + "*" + expb + ")";
            number[i] = a * b;
            if (PointsGame(n - 1)) {
                return true;
            }

            if (b != 0) {
                result[i] = "(" + expa + "/" + expb + ")";
                number[i] = a / b;
                if (PointsGame(n - 1)) {
                    return true;
                }
            }

            if (a != 0) {
                result[i] = "(" + expb + "/" + expa + ")";
                number[i] = b / a;
                if (PointsGame(n - 1)) {
                    return true;
                }
            }

            number[i] = a;
            number[j] = b;
            result[i] = expa;
            result[j] = expb;
        }
    }

    return false;
}

int main(int argc, char* argv[]) 
{
    int x;
    for (int i = 0; i < cards_number; ++i) {
        ostringstream string_builder;
        cout << "the " << i << "th number:";
        cin >> x;
        number[i] = x;
        string_builder << x;
        result[i] = string_builder.str();
    }

    if (PointsGame(cards_number)) {
        cout << "Success." << endl;
    }
    else {
        cout << "Fail." << endl;
    }
    return 0;
}
