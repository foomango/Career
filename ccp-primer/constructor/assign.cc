/*
 * =====================================================================================
 *
 *       Filename:  assign.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/02/2013 05:16:45 PM
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
    A() : a(1) 
    {cout << "constructor1 is called, a=" << a << endl;}
    A(int a1) : a(a1) 
    {cout << "constructor2 is called, a=" << a << endl;}
    A(const A &b) : a(3)
    {cout << "constructor3 is called, a=" << a << endl;}
    ~A() 
    {cout << "destructor is called, a=" << a << endl;}
    void print() 
    {cout << "a=" << a << endl;}
    A& operator = (const A &rh)
    {
        cout << "assign is called" << endl;
        return *this;
    }
private: 
    int a;
};

int main(int argc, char *argv[]) 
{
    //A obj1 = A();
    /*A obj2 = 2;
    obj1.print();
    obj1 = A(2);
    obj1.print();
    obj1 = 22;
    A obj3 = obj2;*/
    A v[2] ={4,};
    cout << "test" << endl;
    return 0;
}
