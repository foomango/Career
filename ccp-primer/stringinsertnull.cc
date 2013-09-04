/*
 * =====================================================================================
 *
 *       Filename:  stringinsertnull.cc
 *
 *    Description:  测试在string中插入空字符
 *
 *        Version:  1.0
 *        Created:  08/26/2013 05:48:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
    string s = "test";
    cout << "before insert:" << s << ":" << s.size() << endl;
    
    s.insert(s.size(), 1, '\0');
    s.insert(s.size(), 2, 'a');
    cout << "after insert:" << s << ":" << s.size() << endl;
    return 0;
}
