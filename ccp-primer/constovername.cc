/*
 * =====================================================================================
 *
 *       Filename:  constovername.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/30/2013 09:32:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WangFengwei (mn), foomango@gmail.com
 *        Company:  HUAZHONG UNIVERSITY OF SCIENCE AND TECHNOLOGY
 *
 * =====================================================================================
 */

#include <iostream>

using std::cout;
using std::endl;

class A 
{
public:
    A():a(0) 
    {
        cout << "A() is called" << endl;
    }

    A() const 
    {
        const_cast<A*>(this)->a = 2;
        cout << "A() const is called" << endl;
    }
    int a;
    void sigma() const {
        const_cast<A*>(this)->a = 2;
//        a = 2;
    }
};

void  bar(A &a) 
{
    cout << "bar(A &a) is called" << " A.a = " << a.a << endl;
}

void bar(const A &a) 
{
    cout << "bar(const A &a) is called" << " A.a = " << a.a << endl;
}

void foo(A *a) 
{
    cout << "void foo(A a) is called" << " A->a = " << a->a << endl;
}

void foo(const A *a) 
{
    cout << "foo(const A a) is called" << " A->a = " << a->a << endl;
}

int main(int argc, char *argv[]) 
{
    const A a;
    A b;
    b.a = 1;
    foo(&a);
    foo(&b);
    bar(a);
    bar(b);
    return 0;
}
