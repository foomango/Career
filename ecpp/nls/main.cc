/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/10/2013 05:33:32 PM
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

class A 
{
public: 
    A() {
        cout << "A's constructor is called" << endl;
    }

    static A& getInstance();
};

A& A::getInstance() 
{
    static A a;
    return a;
}


int main(int argc, char *argv[]) 
{
    cout << "before call getInstance" << endl;
    A::getInstance();
    cout << "after call getInstance" << endl;
    A::getInstance();
    cout << "call getInstance agin" << endl;
    return 0;
}
