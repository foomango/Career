/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/12/2013 03:37:45 PM
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

class B {
public:
    virtual void f() {
        cout << "B::f() is called" << endl;
    }
    virtual void f(int a) {
        cout << "B::f(int) is called" << endl;
    }
};

class D: public B {
public:
    void f() {
        cout << "D::f() is called" << endl;
    }
};

int main(int argc, char *argv[]) 
{
    D d;
    B *pb = &d;

    pb->f(3);
    pb->f();
    d.f(3);
    return 0;
}
