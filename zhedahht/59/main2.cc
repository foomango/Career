/*
 * =====================================================================================
 *
 *       Filename:  main2.cc
 *
 *    Description:  http://foomango.blog.163.com/blog/static/218098074201362881218498/
 *
 *        Version:  1.0
 *        Created:  07/28/2013 08:13:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using std::vector;

typedef void (*TraverseFn)(const vector<char>& data);

void Combination(const char* string, int number, vector<char>& result, TraverseFn fn) 
{
    // Got it
    if (number == 0) {
        fn(result);
        return;
    }

    // Number is small
    if (*string == '\0') {
        return;
    }

    // Use this char
    result.push_back(*string);
    Combination(string + 1, number - 1, result, fn);
    result.pop_back();

    // Skip this char
    Combination(string + 1, number, result, fn);
}

void Combination(const char* string, TraverseFn fn) 
{
    if (string == NULL) {
        return;
    }

    int length = strlen(string);
    vector<char> result;

    for (int i = 1; i <= length; ++i) {
        Combination(string, i, result, fn);
    }
}

void Traverse(const vector<char>& data) 
{
    for (vector<char>::const_iterator iter = data.begin(); 
            iter != data.end(); ++iter) {
        printf("%c", *iter);
    }
    printf("\t");
}

void Usage(const char* prog) 
{
    printf("Usage: %s string\n", prog);
}

int main(int argc, char* argv[]) 
{
    if (argc < 2) {
        Usage(argv[0]);
        exit(-1);
    }

    Combination(argv[1], Traverse);
    printf("\n");

    return 0;
}
