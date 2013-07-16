/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/15/2013 09:23:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <cstring>
#include <cstdio>
#include <cstdlib>

/* Print number stored in string, ignore 0 ate its beginning
 * For example, print "0098" as "98"
 */
void PrintNumber(char* number) 
{
    bool is_beginning0 = true;
    int length = strlen(number);

    for (int i = 0; i < length; i++) {
        if (is_beginning0 && number[i] == '0') {
            continue;
        }
        else {
            printf("%c", number[i]);
        }
    }

    printf("\t");
}

/*
 * Increment a number, When overflow, return true; otherwise return false
 */
bool Increment(char* number) 
{
    bool is_overflow = false;
    int takeover = 0;
    int length = strlen(number);

    // Increment (add 1) operation begins from the end of number
    for (int i = length - 1; i >= 0; i--) {
        int sum = number[i] - '0' + takeover;
        if (i == length - 1) {
            sum++;
        }

        if (sum >= 10) {
            if (i == 0) {
                is_overflow = true;
            }
            else {
                sum -= 10;
                takeover = 1;
                number[i] = '0' + sum;
            }
        }
        else {
            number[i] = '0' + sum;
            break;
        }
    }

    return is_overflow;
}

/*
 * Print numbers from 1 to the maximum number with n digits, in order
 */
void Print1ToMaxOfNDigits2(int n) 
{
    // 0 or minus numbers are invalid input
    if (n <= 0) {
        return;
    }

    // number is initialized as 0
    char* number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';

    while (!Increment(number)) {
        PrintNumber(number);
    }

    printf("\n");

    delete []number;
}

/*
 * length: length of number
 * index: current index of digit in number for this round
 */
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index) 
{
    // we have reached the end of number, print it
    if (index == length - 1) {
        PrintNumber(number);
        return;
    }

    for (int i = 0; i < 10; ++i) {
        // next digit can be 0 to 9
        number[index + 1] = i + '0';

        // go to the next digit
        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
    }
}

/*
 * Print numbers from 1 to the maximum number with n digits, in order
 */
void Print1ToMaxOfNDigits3(int n) 
{
    // 0 or minus numbers are invalid input
    if (n <= 0) {
        return;
    }

    char* number = new char[n + 1];
    number[n] = '\0';

    for (int i = 0; i < 10; ++i) {
        // first digit can be 0 to 9
        number[0] = i + '0';

        Print1ToMaxOfNDigitsRecursively(number, n, 0);
    }

    delete[] number;
}

void usage(const char* prog) 
{
    printf("usage: %s algorithm number\n", prog);
}

int main(int argc, char* argv[]) 
{
    if (argc < 3) {
        usage(argv[0]);
        exit(-1);
    }

    int algorithm = atoi(argv[1]);
    int number = atoi(argv[2]);

    switch(algorithm) {
        case 1:
            Print1ToMaxOfNDigits3(number);
            break;
        case 2:
            Print1ToMaxOfNDigits2(number);
            break;
        default:
            usage(argv[0]);
            exit(-1);
    }

    return 0;
}
