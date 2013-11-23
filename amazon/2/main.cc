/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/25/2013 04:39:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <vector>
#include <string>

using namespace std;

vector < string > Dequeue(int count, vector < string > queue) {
    vector<string> result;

    vector<string> temp = queue;
    int n = count;
    int i = 0;

    while(temp.size() > 0) {
        i = (((i + n) % temp.size()) - 1) % temp.size();
        result.push_back(temp.at(i));

        for (int j = i; j < temp.size() - 1; ++j) {
            temp[j] = temp[j + 1];
        }
        temp.pop_back();
        --i;
    }

    return result;
}

int main(int argc, char *argv[]) 
{
    string str[] = {"a", "b", "c", "d", "e"};
    int n = 3;
    vector<string> queue(str, str + sizeof(str) / sizeof(str[0]));
    vector<string> result;
    result = Dequeue(n, queue);
    return 0;
}
