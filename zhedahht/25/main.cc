/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/20/2013 03:07:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>

int NumberOf1(const char* strn);
int PowerBase10(unsigned int n);

/*
 * Find the number of 1 in an integer with radix 10
 * Input: n - an integer
 * Output: the number of 1 int with radix
 */
int NumberOf1BeforeBetween1AndNSolution2(int n) 
{
    if (n <= 0) 
        return 0;

    // convert the integer into a string
    char strn[50];
    sprintf(strn, "%d", n);
    return NumberOf1(strn);
}

/*
 * Find the number of 1 in an integer with radix 10
 * Input: strn - a string, which represents an integer
 * Output: the number of 1 in n with radix
 */
int NumberOf1(const char* strn) 
{
    if (!strn || *strn < '0' || *strn > '9' || *strn == '\0') 
        return 0;

    int first_digit = *strn - '0';
    int length = strlen(strn);

    // the integer contains only one digit
    if (length == 1 && first_digit == 0) {
        return 0;
    }

    if (length == 1 && first_digit > 0) {
        return 1;
    }

    // suppose the integer is 21345
    // num_first_digit is the number of 1 of 10000-19999 due to the first digit
    int num_first_digit = 0;
    // num_other_digit is the number of 1 of 01346-21345 due to all digits
    // exept the first one
    int num_other_digit = first_digit * (length - 1) * PowerBase10(length - 2);
    // num_recusive is the number of 1 of integer 1345
    int num_recursive = NumberOf1(strn + 1);

    // if the first digit is greater than 1, suppose in integer 21345 
    // number of 1 due to the first digit is 10^4. It's 10000-19999
    if (first_digit > 1) {
        num_first_digit = PowerBase10(length - 1);
    }
    // if the first digit equals to 1, suppose in integer 12345 
    // number of 1 due to the first digit is 2346. It's 10000-12345
    else if (first_digit == 1) {
        num_first_digit = atoi(strn + 1) + 1;
    }

    return num_first_digit + num_other_digit + num_recursive;
}

/*
 * Calculate 10^n
 */
int PowerBase10(unsigned int n) 
{
    int result = 1;
    for (unsigned int i = 0; i < n; ++i) {
        result *= 10;
    }

    return result;
}

int NumberOf1BeforeBetween1AndNSolution3(int n) 
{
    int count = 0;
    int a = 0;
    int weight = 1;

    int current_bit;
    int temp = n;

    if (n <= 0) {
        return 0;
    }

    while (temp) {
        current_bit = temp % 10;
        count += current_bit * a;

        if (current_bit > 1) {
            count += weight;
        }
        else if(current_bit == 1) {
            count += n % weight + 1;
        }

        a = 10 * a + weight;
        weight *= 10;
        temp /= 10;
    }

    return count;
}

void Usage(const char* prog) 
{
    printf("Usage: %s algorithm number\n");
}

int main(int argc, char* argv[]) 
{
    if (argc < 3) {
        Usage(argv[0]);
        exit(-1);
    }

    int algorithm = atoi(argv[1]);
    int number = atoi(argv[2]);
    int numof1 = 0;

    switch(algorithm) {
        case 2:
            numof1 = NumberOf1BeforeBetween1AndNSolution2(number);
            break;
        case 3:
            numof1 = NumberOf1BeforeBetween1AndNSolution3(number);
            break;
        default:
            Usage(argv[0]);
            exit(-1);
    }

    printf("%d\n", numof1);

    return 0;
}
